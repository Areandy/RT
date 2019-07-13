/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shading.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:08:25 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 17:08:26 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int			shadow(int i, t_vec hit, t_params *p)
{
	t_id_dist	tmp_i_d;

	obj_hit(&tmp_i_d.id, &tmp_i_d.dist,
		(t_ray){hit, unit_vector(p->light)}, p);
	if (length(p->light_sources[i].ori - hit) > tmp_i_d.dist)
		return (0);
	return (1);
}

void		diff_spec(int i, t_vec normal, t_params *p)
{
	t_vec	specular_ray;

	p->dot_product = dot(normal, p->light);
	if (p->dot_product > 0)
		p->light_coef += p->light_sources[i].intensity
			* p->dot_product / (length(normal) * length(p->light));
	if ((p->obj_arr[p->obj_id].specular >= 10)
		&& (p->obj_arr[p->obj_id].specular <= 1000))
	{
		specular_ray = to_vec(2 * p->dot_product) * normal - p->light;
		p->dot_product = dot(specular_ray, -p->tmp_ray.dir);
		if (p->dot_product > 0)
			p->light_coef += p->light_sources[i].intensity *
				pow(p->dot_product / (length(specular_ray)
					* length(-p->tmp_ray.dir)), p->obj_arr[p->obj_id].specular);
	}
}

int			save_me(int i, t_vec hit, t_vec normal, t_params *p)
{
	p->light = (p->light_sources[i].type == 2) ? p->light_sources[i].ori - hit
		: p->light_sources[i].dir;
	if (((dot(unit_vector(p->light), normal) < 0)
		|| (dot(p->tmp_ray.dir, normal) > 0))
		&& ((dot(unit_vector(p->light), normal) > 0)
		|| (dot(p->tmp_ray.dir, normal) < 0)))
		return (0);
	if (!(shadow(i, hit, p)))
		return (0);
	diff_spec(i, normal, p);
	return (1);
}

double		compute_light(t_vec hit, t_vec normal, int obj_id, t_params *p)
{
	int		i;

	i = -1;
	p->light_coef = 0.0;
	p->obj_id = obj_id;
	while (++i < p->light_amount)
	{
		if (p->light_sources[i].type == 1)
			p->light_coef += p->light_sources[i].intensity;
		else if (!(save_me(i, hit, normal, p)))
			continue ;
	}
	return ((p->light_coef > 1.0) ? 1.0 : p->light_coef);
}

t_color		shading(t_id_dist obj_id_dist, t_vec hit,
					int depth, t_params *p)
{
	double		ref;
	t_vec		normal;
	t_vec		ref_ray_dir;
	t_color		ref_color;
	t_color		color;

	ref = (p->obj_arr[obj_id_dist.id].reflection > 1.0) ?
		1.0 : p->obj_arr[obj_id_dist.id].reflection;
	color = p->obj_arr[obj_id_dist.id].color;
	if (p->obj_arr[obj_id_dist.id].texture != NULL)
		color = spherical_mapping(p->obj_arr[obj_id_dist.id].texture,
			hit, p->obj_arr[obj_id_dist.id].center);
	normal = p->obj_arr[obj_id_dist.id]
		.get_normal(&p->obj_arr[obj_id_dist.id], hit, p);
	color *= to_vec(compute_light(hit, normal, obj_id_dist.id, p));
	if ((depth < 1) || (ref <= 0.0))
		return (color);
	ref_ray_dir = reflect(-p->tmp_ray.dir, normal);
	ref_color = ray_trace_2(hit, ref_ray_dir, depth - 1, p);
	return (color * to_vec(1.0 - ref) + ref_color * to_vec(ref));
}
