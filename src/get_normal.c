/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_normal.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:47:11 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:47:12 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_vec		sphere_normal(t_obj *obj, t_vec hit, t_params *p)
{
	t_vec	norm;

	norm = unit_vector(hit - obj->center);
	if (dot(p->tmp_ray.dir, norm) < 0.0)
		return (norm);
	return (-norm);
}

t_vec		cylinder_normal(t_obj *obj, t_vec hit, t_params *p)
{
	double	m;
	t_vec	norm;

	m = dot(p->tmp_ray.dir, obj->dir) * p->tmp_i_d.dist
		+ dot(p->tmp_ray.ori - obj->center, obj->dir);
	norm = unit_vector(hit - obj->center -
		obj->dir * to_vec(m));
	if (dot(p->tmp_ray.dir, norm) < 0.0)
		return (norm);
	return (-norm);
}

t_vec		cone_normal(t_obj *obj, t_vec hit, t_params *p)
{
	double	m;
	t_vec	norm;

	m = dot(p->tmp_ray.dir, obj->dir) * p->tmp_i_d.dist
		+ dot(p->tmp_ray.ori - obj->center, obj->dir);
	norm = unit_vector(hit - obj->center
		- to_vec((1.0 + pow2(obj->angle)) * m) * obj->dir);
	if (dot(p->tmp_ray.dir, norm) < 0.0)
		return (norm);
	return (-norm);
}

t_vec		plane_normal(t_obj *obj, t_vec hit, t_params *p)
{
	hit += to_vec(1);
	obj->dir = unit_vector(obj->dir);
	if (dot(p->tmp_ray.dir, obj->dir) < 0.0)
		return (obj->dir);
	else
		return (-obj->dir);
}

t_vec		parabl_normal(t_obj *obj, t_vec hit, t_params *p)
{
	double	m;
	t_vec	norm;

	m = dot(p->tmp_ray.dir, obj->dir) * p->tmp_i_d.dist
		+ dot(p->tmp_ray.ori - obj->center, obj->dir);
	norm = unit_vector(hit - obj->center - obj->dir * to_vec(m + obj->k));
	if (dot(p->tmp_ray.dir, norm) < 0.0)
		return (norm);
	return (-norm);
}
