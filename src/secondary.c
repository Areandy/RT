/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   secondary.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:32:55 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:32:57 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

int			img_put_pixel(t_params *p, int x, int y, int color)
{
	Uint32	*pixels;

	if (x < 0 || y < 0 || x >= p->width || y >= p->height || p->surface == NULL)
		return (-1);
	SDL_LockSurface(p->surface);
	pixels = (Uint32 *)p->surface->pixels;
	pixels[y * p->width + x] = color;
	SDL_UnlockSurface(p->surface);
	return (1);
}

t_color		int_to_color(int color)
{
	t_color res;

	res[0] = color >> 16;
	res[1] = (color - ((Uint8)res[0] << 16)) >> 8;
	res[2] = color - ((Uint8)res[0] << 16) - ((Uint8)res[1] << 8);
	return (res);
}

double		pow2(double a)
{
	return (a * a);
}

t_vec		point_at_parameter(double t, t_ray ray)
{
	return (ray.ori + to_vec(t) * ray.dir);
}

int			get_color(t_color color)
{
	int		r;
	int		g;
	int		b;

	r = (int)(color[0]);
	g = (int)(color[1]);
	b = (int)(color[2]);
	return ((r << 16) | (g << 8) | b);
}
