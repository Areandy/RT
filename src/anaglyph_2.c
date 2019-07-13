/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anaglyph_2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 15:22:18 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 15:22:19 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			render1(t_params *p)
{
	int		x;
	int		y;
	int		tmp;

	y = 0;
	while (y < p->height)
	{
		x = 0;
		while (x < p->width)
		{
			if (check_ui(x, y))
			{
				x += p->pixel_view;
				continue ;
			}
			tmp = get_color(ray_trace_2(p->camera->ori,
				prepere_dir(x, y, p), p->reflection_depth, p));
			pixel_view(x, y, tmp, p);
			x += p->pixel_view;
		}
		y += p->pixel_view;
	}
}

Uint32			map_rgb(t_vec rgb)
{
	if ((int)rgb[0] > 255)
		rgb[0] = 255;
	if ((int)rgb[1] > 255)
		rgb[1] = 255;
	if ((int)rgb[2] > 255)
		rgb[2] = 255;
	return (((int)rgb[0] << 16) + ((int)rgb[1] << 8) + (int)rgb[2]);
}

void			give_c_res(t_blender *b, SDL_Surface *sur,
					SDL_Surface *sur1)
{
	int		x;
	int		y;

	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
		{
			b->c_sur = int_to_color(b->p_sur[x + y * sur->w]);
			b->c_sur1 = int_to_color(b->p_sur1[x + y * sur1->w]);
			b->c_res[0] = (b->c_sur[0] + b->c_sur1[0]) < 255
				? b->c_sur[0] + b->c_sur1[0] : 255;
			b->c_res[1] = (b->c_sur[1] + b->c_sur1[1]) < 255
				? b->c_sur[1] + b->c_sur1[1] : 255;
			b->c_res[2] = (b->c_sur[2] + b->c_sur1[2]) < 255
				? b->c_sur[2] + b->c_sur1[2] : 255;
			b->p_res[x + y * sur->w] = map_rgb(b->c_res);
		}
	}
}
