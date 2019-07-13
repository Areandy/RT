/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   anaglyph.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:36:06 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 14:36:06 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

SDL_Surface		*blend_surfaces(SDL_Surface *sur, SDL_Surface *sur1)
{
	t_blender	b;

	b.res = SDL_CreateRGBSurface(0, sur->w, sur1->h, 32, 0, 0, 0, 0);
	b.p_sur = sur->pixels;
	b.p_sur1 = sur1->pixels;
	b.p_res = b.res->pixels;
	SDL_LockSurface(sur);
	SDL_LockSurface(sur1);
	SDL_LockSurface(b.res);
	give_c_res(&b, sur, sur1);
	SDL_UnlockSurface(sur);
	SDL_UnlockSurface(sur1);
	SDL_UnlockSurface(b.res);
	return (b.res);
}

void			red_blue_version(SDL_Surface *sur, int color)
{
	Uint32		*pixels;
	int			x;
	int			y;
	t_vec		col;

	SDL_LockSurface(sur);
	pixels = (Uint32 *)sur->pixels;
	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
		{
			col = int_to_color(pixels[x + y * sur->w]);
			col[0] = (0.21 * col[0] + 0.72 * col[1] + 0.07 * col[2]) / 2;
			col[1] = col[0];
			col[2] = col[0];
			if (color == RED)
				col[0] *= 4;
			if (color == BLUE)
				col[2] *= 4;
			pixels[x + y * sur->w] = map_rgb(col);
		}
	}
	SDL_UnlockSurface(sur);
}

void			fill_background(SDL_Surface *background, SDL_Surface *scene)
{
	int			x;
	int			y;
	Uint32		*pixels;
	Uint32		*b_pixels;

	y = 0;
	SDL_LockSurface(background);
	SDL_LockSurface(scene);
	pixels = (Uint32 *)scene->pixels;
	b_pixels = (Uint32 *)background->pixels;
	while (y < scene->h)
	{
		x = 0;
		while (x < scene->w)
		{
			if (pixels[y * scene->w + x] == 0)
			{
				pixels[y * scene->w + x] = b_pixels[y * scene->w + x];
			}
			x++;
		}
		y++;
	}
	SDL_UnlockSurface(background);
	SDL_UnlockSurface(scene);
}

SDL_Surface		*surface_cpy(SDL_Surface *sur)
{
	SDL_Surface	*new_sur;
	int			x;
	int			y;
	Uint32		*pixels;
	Uint32		*new_pixels;

	new_sur = SDL_CreateRGBSurface(0, sur->w, sur->h, 32, 0, 0, 0, 0);
	SDL_BlitSurface(sur, NULL, new_sur, NULL);
	SDL_LockSurface(sur);
	SDL_LockSurface(new_sur);
	pixels = sur->pixels;
	new_pixels = new_sur->pixels;
	y = -1;
	while (++y < sur->h)
	{
		x = -1;
		while (++x < sur->w)
			new_pixels[y * sur->w + x] = pixels[y * sur->w + x];
	}
	SDL_UnlockSurface(sur);
	SDL_UnlockSurface(new_sur);
	return (new_sur);
}

void			anaglyph_render(t_params *p)
{
	SDL_Surface *red;
	SDL_Surface *blue;
	SDL_Surface *blended;

	camera_move(3, p);
	render1(p);
	red = surface_cpy(p->surface);
	red_blue_version(red, RED);
	camera_move(2, p);
	render1(p);
	blue = surface_cpy(p->surface);
	red_blue_version(blue, BLUE);
	blended = blend_surfaces(red, blue);
	SDL_BlitSurface(blended, NULL, p->surface, NULL);
	SDL_FreeSurface(red);
	SDL_FreeSurface(blue);
	SDL_FreeSurface(blended);
	render_ui(p);
}
