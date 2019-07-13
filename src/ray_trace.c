/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ray_trace.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:42:38 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 16:42:39 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_color			ray_trace_2(t_vec ori, t_vec dir, int depth, t_params *p)
{
	t_ray		ray;
	t_id_dist	tmp;

	ray = (t_ray){ori, unit_vector(dir)};
	p->tmp_ray.ori = ori;
	p->tmp_ray.dir = ray.dir;
	obj_hit(&tmp.id, &tmp.dist, ray, p);
	if (tmp.id != -1 && p->black == 1)
		return (gray_scale(shading(tmp, point_at_parameter(tmp.dist, ray),
			depth, p)));
	else if (tmp.id != -1)
		return (shading(tmp, point_at_parameter(tmp.dist, ray), depth, p));
	return (to_vec(0));
}

t_color			ray_trace(float u, float v, t_params *p)
{
	t_ray		ray;
	t_vec		ray_dir;
	t_id_dist	tmp;

	ray_dir = (t_vec)
	{
		(2.0 * u - 1.0) * p->fov * p->aspect_ratio,
		(1.0 - 2.0 * v) * p->fov,
		-1.0
	};
	rotate_xyz(&ray_dir, p);
	ray = (t_ray){p->camera->ori, unit_vector(ray_dir)};
	p->tmp_ray.ori = ray.ori;
	p->tmp_ray.dir = ray.dir;
	obj_hit(&tmp.id, &tmp.dist, ray, p);
	if (tmp.id != -1 && p->black == 1)
		return (gray_scale(shading(tmp, point_at_parameter(tmp.dist, ray),
			p->reflection_depth, p)));
	else if (tmp.id != -1)
		return (shading(tmp, point_at_parameter(tmp.dist, ray),
			p->reflection_depth, p));
	else
		return (to_vec(0));
}
