/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   textures.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:09:31 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 17:09:32 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_color		gray_scale(t_color color)
{
	color[0] = color[0] * 0.21 + color[1] * 0.72 + color[2] * 0.07;
	color[1] = color[0];
	color[2] = color[0];
	return (color);
}

Uint32		get_texture_color(SDL_Surface *texture, int x, int y)
{
	int		bpp;
	uint8_t	*pixels;

	bpp = texture->format->BytesPerPixel;
	pixels = (uint8_t *)texture->pixels + y * texture->pitch + x * bpp;
	if (bpp == 1)
		return (*pixels);
	if (bpp == 2)
		return (*(uint16_t *)pixels);
	if (bpp == 4 || bpp == 3)
	{
		if (SDL_BYTEORDER == SDL_BIG_ENDIAN)
			return (pixels[0] << 16 | pixels[1] << 8 | pixels[2]);
		else
			return (pixels[0] | pixels[1] << 8 | pixels[2] << 16);
	}
	if (bpp == 4)
		return (*(Uint32 *)pixels);
	return (0);
}

t_color		spherical_mapping(SDL_Surface *texture, t_vec hit, t_vec center)
{
	t_vec	d;
	double	u;
	double	v;

	d = unit_vector(hit - center);
	u = 0.5 + (atan2(d[2], d[0]) / (PI * 2));
	v = 0.5 - (asin(d[1]) / PI);
	return (int_to_color(get_texture_color(texture,
		u * texture->w, v * texture->h)));
}

int			antialiasing(double x1, double y1, t_params *p)
{
	t_pair		uv;
	int			t[4];
	t_color		color;

	color = (t_color){0, 0, 0};
	t[2] = x1;
	t[3] = y1;
	t[0] = -1;
	while (++t[0] < 3)
	{
		t[1] = -1;
		while (++t[1] < 3)
		{
			uv.d1 = ((float)t[2] + (t[1] - 3 / 2) + 0.5
				+ (double)(rand() % 101) / 100) / (float)p->width;
			uv.d2 = ((float)t[3] + (t[0] - 3 / 2) + 0.5
				+ (double)(rand() % 101) / 100) / (float)p->height;
			color += ray_trace(uv.d1, uv.d2, p);
		}
	}
	color[0] = color[0] / 9;
	color[1] = color[1] / 9;
	color[2] = color[2] / 9;
	return (get_color(color));
}
