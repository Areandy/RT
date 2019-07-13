/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:34:34 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:34:35 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		rotate_x(t_vec *v, float angle)
{
	float	tmp_y;

	tmp_y = (*v)[1];
	(*v)[1] = cos(angle) * tmp_y + sin(angle) * (*v)[2];
	(*v)[2] = cos(angle) * (*v)[2] - sin(angle) * tmp_y;
}

void		rotate_y(t_vec *v, float angle)
{
	float	tmp_x;

	tmp_x = (*v)[0];
	(*v)[0] = cos(angle) * tmp_x - sin(angle) * (*v)[2];
	(*v)[2] = cos(angle) * (*v)[2] + sin(angle) * tmp_x;
}

void		rotate_z(t_vec *v, float angle)
{
	float	tmp_x;

	tmp_x = (*v)[0];
	(*v)[0] = cos(angle) * tmp_x - sin(angle) * (*v)[1];
	(*v)[1] = cos(angle) * (*v)[1] + sin(angle) * tmp_x;
}

void		rotate_xyz(t_vec *v, t_params *p)
{
	rotate_x(v, p->camera->dir[0]);
	rotate_y(v, p->camera->dir[1]);
	rotate_z(v, p->camera->dir[2]);
}
