/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ui.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:31:00 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 17:31:01 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		set_buttons(t_params *p)
{
	p->btn[0] = (SDL_Rect){31, 54, 28, 28};
	p->btn[1] = (SDL_Rect){72, 54, 28, 28};
	p->btn[2] = (SDL_Rect){112, 54, 28, 28};
	p->btn[3] = (SDL_Rect){31, 96, 28, 28};
	p->btn[4] = (SDL_Rect){72, 96, 28, 28};
	p->btn[5] = (SDL_Rect){112, 96, 28, 28};
	p->btn[6] = (SDL_Rect){176, 40, 15, 15};
	p->btn[7] = (SDL_Rect){320, 40, 15, 15};
	p->btn[8] = (SDL_Rect){176, 81, 15, 15};
	p->btn[9] = (SDL_Rect){320, 81, 15, 15};
	p->btn[10] = (SDL_Rect){176, 110, 134, 24};
}

void		wich_shape(t_params *p)
{
	if (p->obj_arr[p->tmp_i_d.id].get_dist == shpere_hit)
		render_text(p, "Sphere.shape", 40, 6);
	else if (p->obj_arr[p->tmp_i_d.id].get_dist == cylinder_hit)
		render_text(p, "Cylinder.shape", 40, 6);
	else if (p->obj_arr[p->tmp_i_d.id].get_dist == plane_hit)
		render_text(p, "Plane.shape", 40, 6);
	else if (p->obj_arr[p->tmp_i_d.id].get_dist == cone_hit)
		render_text(p, "Cone.shape", 40, 6);
	else if (p->obj_arr[p->tmp_i_d.id].get_dist == parabl_hit)
		render_text(p, "Parabola.shape", 40, 6);
	else
		render_text(p, "The void", 40, 6);
}

void		render_ui(t_params *p)
{
	p->surface->locked = 0;
	SDL_BlitSurface(p->ui_window, NULL, p->surface,
		&(SDL_Rect){0, 0, 0, 0});
	wich_shape(p);
	if (p->antialiasing)
		SDL_BlitSurface(p->check_icon, NULL, p->surface,
			&(SDL_Rect){176, 40, 0, 0});
	if (p->black)
		SDL_BlitSurface(p->check_icon, NULL, p->surface,
			&(SDL_Rect){320, 40, 0, 0});
	if (p->pixel_view == 10)
		SDL_BlitSurface(p->check_icon, NULL, p->surface,
			&(SDL_Rect){176, 81, 0, 0});
	if (p->anaglyph)
		SDL_BlitSurface(p->check_icon, NULL, p->surface,
			&(SDL_Rect){320, 81, 0, 0});
	SDL_UpdateWindowSurface(p->win_ptr);
}

int			check_ui(int x, int y)
{
	if ((x >= 0 && x <= 490)
		&& (y >= 0 && y <= 140))
		return (1);
	return (0);
}
