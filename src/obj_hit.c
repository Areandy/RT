/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   obj_hit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 16:40:08 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 16:40:09 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int			compute_quadratic(t_vec tmp, t_pair *res)
{
	double		q;

	q = tmp[1] * tmp[1] - 4.0 * tmp[0] * tmp[2];
	if (sqrt(q) < 0)
		return (!(set_pair(res, -1, -1)));
	return (set_pair(res,
		(-tmp[1] - sqrt(q)) / (2.0 * tmp[0]),
		(-tmp[1] + sqrt(q)) / (2.0 * tmp[0])));
}

int			set_id_dist(int flag, double *dist, int tmp_id, t_params *p)
{
	if (flag == 1)
	{
		*dist = p->res.d1;
		p->tmp_i_d.id = tmp_id;
		p->tmp_i_d.dist = p->res.d1;
		return (tmp_id);
	}
	else if (flag == 2)
	{
		*dist = p->res.d2;
		p->tmp_i_d.id = tmp_id;
		p->tmp_i_d.dist = p->res.d2;
		return (tmp_id);
	}
	return (-1);
}

void		obj_hit(int *id, double *dist, t_ray ray, t_params *p)
{
	int		tmp_id;
	t_pair	res;

	*id = -1;
	*dist = __DBL_MAX__;
	tmp_id = -1;
	while (++tmp_id < p->obj_amount)
	{
		p->obj_arr[tmp_id].get_dist(&p->obj_arr[tmp_id], ray, &res);
		p->res = res;
		if (res.d1 > 0.00001 && res.d1 < *dist)
			if (!(slice_intersect(res.d1, &p->obj_arr[tmp_id], ray)))
				*id = set_id_dist(1, dist, tmp_id, p);
		if (res.d2 > 0.00001 && res.d2 < *dist)
			if (!(slice_intersect(res.d2, &p->obj_arr[tmp_id], ray)))
				*id = set_id_dist(2, dist, tmp_id, p);
	}
}
