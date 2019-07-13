/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_event.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 17:02:22 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 17:02:23 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		button_helper_2(int btn, t_params *p)
{
	if (btn == 6)
	{
		p->antialiasing = p->antialiasing == 1 ? 0 : 1;
		create_threads(p);
	}
	else if (btn == 7)
	{
		p->black = p->black == 1 ? 0 : 1;
		create_threads(p);
	}
	else if (btn == 8)
	{
		p->pixel_view = (p->pixel_view == 1) ? 10 : 1;
		create_threads(p);
	}
	else if (btn == 9)
	{
		p->anaglyph = p->anaglyph == 1 ? 0 : 1;
		create_threads(p);
	}
	else if (btn == 10)
		screen_shot(p);
}

void		button_hendler(int btn, t_params *p)
{
	if (btn == 0)
		move_obj(1.0, 1, p);
	else if (btn == 1)
		move_obj(1.0, 2, p);
	else if (btn == 2)
		move_obj(1.0, 3, p);
	else if (btn == 3)
		move_obj(-1.0, 1, p);
	else if (btn == 4)
		move_obj(-1.0, 2, p);
	else if (btn == 5)
		move_obj(-1.0, 3, p);
	else
		button_helper_2(btn, p);
}

int			ui_hendler(int x, int y, t_params *p)
{
	int		i;
	int		res;

	i = -1;
	res = -1;
	while (++i < BTN_AMOUNT)
	{
		if ((x > p->btn[i].x && x < p->btn[i].w + p->btn[i].x)
			&& (y > p->btn[i].y && y < p->btn[i].h + p->btn[i].y))
		{
			button_hendler(i, p);
			return (1);
		}
	}
	return (1);
}

void		find_obj(t_vec ori, t_vec dir, t_params *p)
{
	t_ray		ray;
	t_id_dist	tmp;

	ray = (t_ray){ori, unit_vector(dir)};
	p->tmp_ray.ori = ori;
	p->tmp_ray.dir = ray.dir;
	obj_hit(&tmp.id, &tmp.dist, ray, p);
}

void		sdl_event(t_params *p, SDL_Event *ev)
{
	int x;
	int y;

	if (ev->type == SDL_KEYDOWN)
		key_press(ev->key.keysym.sym, p);
	else if (ev->type == SDL_QUIT)
	{
		SDL_FreeSurface(p->surface);
		SDL_DestroyWindow(p->win_ptr);
		SDL_Quit();
		exit(1);
	}
	else if (ev->type == SDL_MOUSEBUTTONDOWN)
	{
		SDL_GetMouseState(&x, &y);
		if (check_ui(x, y))
			if (ui_hendler(x, y, p))
				return ;
		find_obj(p->camera->ori,
			prepere_dir(x, y, p), p);
		render_ui(p);
	}
}
