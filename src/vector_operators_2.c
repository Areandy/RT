/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators_2.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:31:19 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:31:21 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_vec		to_vec(double val)
{
	return ((t_vec){val, val, val});
}

void		height_edge(t_obj *obj, t_ray ray, double rd_cd, t_pair *tmp_res)
{
	double	tmp;
	double	rd_od;

	rd_od = dot(ray.ori - obj->center, obj->dir);
	tmp = rd_cd * tmp_res->d1 + rd_od;
	if (obj->height > 0)
		if (tmp < obj->height_down || tmp > obj->height)
			tmp_res->d1 = -1;
	tmp = rd_cd * tmp_res->d2 + rd_od;
	if (obj->height > 0)
		if (tmp < obj->height_down || tmp > obj->height)
			tmp_res->d2 = -1;
}

int			slice_intersect(double dist, t_obj *obj, t_ray ray)
{
	if (!(check_vec(obj->slice_ori) || !(check_vec(obj->slice_dir))))
		return (0);
	if (length((to_vec(dist) * ray.dir + ray.ori) - obj->slice_ori)
		* dot((to_vec(dist) * ray.dir + ray.ori)
		- obj->slice_ori, obj->slice_dir) / (length(obj->slice_dir)) <= 0.0)
		return (1);
	return (0);
}

void		move_obj(double val, int xyz, t_params *p)
{
	if (xyz == 1)
		p->obj_arr[p->tmp_i_d.id].center += (t_vec){val, 0.0, 0.0};
	else if (xyz == 2)
		p->obj_arr[p->tmp_i_d.id].center += (t_vec){0.0, val, 0.0};
	else if (xyz == 3)
		p->obj_arr[p->tmp_i_d.id].center += (t_vec){0.0, 0.0, val};
	if (p->obj_arr[p->tmp_i_d.id].slice_type == 1
		&& check_vec(p->obj_arr[p->tmp_i_d.id].slice_ori))
	{
		if (xyz == 1)
			p->obj_arr[p->tmp_i_d.id].slice_ori += (t_vec){val, 0.0, 0.0};
		else if (xyz == 2)
			p->obj_arr[p->tmp_i_d.id].slice_ori += (t_vec){0.0, val, 0.0};
		else if (xyz == 3)
			p->obj_arr[p->tmp_i_d.id].slice_ori += (t_vec){0.0, 0.0, val};
	}
	create_threads(p);
}
