/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_operators_1.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:32:26 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:32:27 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

double		dot(t_vec a, t_vec b)
{
	return (a[0] * b[0] + a[1] * b[1] + a[2] * b[2]);
}

double		length(t_vec v)
{
	return (sqrt(pow2(v[0]) + pow2(v[1]) + pow2(v[2])));
}

t_vec		cross(t_vec a, t_vec b)
{
	return ((t_vec){
		a[1] * b[2] - a[2] * b[1],
		-(a[0] * b[2] - a[2] * b[0]),
		a[0] * b[1] - a[1] * b[0]
	});
}

t_vec		unit_vector(t_vec v)
{
	return (to_vec(1.0 / length(v)) * v);
}

t_vec		reflect(t_vec ray_dir, t_vec normal)
{
	return (to_vec(2 * dot(ray_dir, normal)) * normal - ray_dir);
}
