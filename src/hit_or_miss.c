/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hit_or_miss.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:38:00 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:38:01 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			shpere_hit(t_obj *obj, t_ray ray, t_pair *res)
{
	t_vec		co;
	t_vec		tmp;

	co = ray.ori - obj->center;
	tmp[0] = dot(ray.dir, ray.dir);
	tmp[1] = 2.0 * dot(ray.dir, co);
	tmp[2] = dot(co, co) - obj->radius * obj->radius;
	if (!(compute_quadratic(tmp, res)))
		return ;
}

void			cylinder_hit(t_obj *obj, t_ray ray, t_pair *res)
{
	t_vec	tmp;
	t_vec	oc;
	double	rd_cd;
	double	oc_v;

	oc = ray.ori - obj->center;
	rd_cd = dot(ray.dir, obj->dir);
	oc_v = dot(oc, obj->dir);
	tmp[0] = dot(ray.dir, ray.dir) - rd_cd * rd_cd;
	tmp[1] = 2 * (dot(ray.dir, oc) - rd_cd * oc_v);
	tmp[2] = dot(oc, oc) - oc_v * oc_v - obj->radius * obj->radius;
	if (compute_quadratic(tmp, res))
		height_edge(obj, ray, rd_cd, res);
}

void			cone_hit(t_obj *obj, t_ray ray, t_pair *res)
{
	t_vec	oc;
	t_vec	tmp;
	double	rd_cd;
	double	huh;

	oc = ray.ori - obj->center;
	huh = 1.0 + pow2(obj->angle);
	rd_cd = dot(ray.dir, obj->dir);
	tmp[0] = dot(ray.dir, ray.dir) - huh * pow2(rd_cd);
	tmp[1] = 2 * (dot(ray.dir, oc) - huh * rd_cd * dot(oc, obj->dir));
	tmp[2] = dot(oc, oc) - huh * pow2(dot(oc, obj->dir));
	if (compute_quadratic(tmp, res))
		height_edge(obj, ray, rd_cd, res);
}

void			plane_hit(t_obj *obj, t_ray ray, t_pair *res)
{
	double		tmp1;
	double		tmp2;

	tmp1 = -dot(ray.ori - obj->center, obj->dir);
	tmp2 = dot(ray.dir, obj->dir);
	if (tmp2 != 0.0)
	{
		set_pair(res, tmp1 / tmp2, -1);
		if (obj->radius > 0.0 && length((to_vec(res->d1) * ray.dir + ray.ori)
			- obj->center) > obj->radius)
			res->d1 = -1;
	}
	else
		set_pair(res, -1, -1);
}

void			parabl_hit(t_obj *obj, t_ray ray, t_pair *res)
{
	t_vec		tmp;
	t_vec		oc;
	double		oc_od;
	double		rd_cd;

	oc = ray.ori - obj->center;
	oc_od = dot(oc, obj->dir);
	rd_cd = dot(ray.dir, obj->dir);
	tmp[0] = dot(ray.dir, ray.dir) - pow2(rd_cd);
	tmp[1] = 2 * (dot(ray.dir, oc) - rd_cd * (oc_od + 2.0 * obj->k));
	tmp[2] = dot(oc, oc) - oc_od * (oc_od + 4.0 * obj->k);
	if (compute_quadratic(tmp, res))
		height_edge(obj, ray, rd_cd, res);
}
