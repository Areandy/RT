/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:47:33 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:47:34 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

t_params	*camera_move(int dir, t_params *p)
{
	t_vec		v;

	v = (t_vec){0., 0., 0.5};
	rotate_xyz(&v, p);
	if (dir == 0)
		p->camera->ori -= v;
	else if (dir == 1)
		p->camera->ori += v;
	else
	{
		rotate_y(&v, M_PI / 2);
		v[1] = 0;
		if (dir == 2)
			p->camera->ori -= v;
		else if (dir == 3)
			p->camera->ori += v;
	}
	return (p);
}

t_params	*camera_down_up(int dir, t_params *p)
{
	t_vec	vec;

	vec = (t_vec){0, 0.5f, 0};
	if (dir)
		p->camera->ori += vec;
	else
		p->camera->ori -= vec;
	return (p);
}

t_params	*camera_dir_helper(int axis, int sign, t_params *p)
{
	if (sign)
		p->camera->dir[axis] += 0.1;
	else
		p->camera->dir[axis] -= 0.1;
	return (p);
}

void		camera_dir_2(SDL_Keycode key, t_params *p)
{
	if (key == SDLK_i)
	{
		p->anaglyph = p->anaglyph == 1 ? 0 : 1;
		create_threads(p);
	}
	else if (key == SDLK_u)
	{
		p->antialiasing = p->antialiasing == 1 ? 0 : 1;
		create_threads(p);
	}
	else if (key == SDLK_1)
	{
		p->black = p->black == 1 ? 0 : 1;
		create_threads(p);
	}
}

void		camera_dir(SDL_Keycode key, t_params *p)
{
	if (key == SDLK_q)
		create_threads(camera_dir_helper(1, 0, p));
	else if (key == SDLK_e)
		create_threads(camera_dir_helper(1, 1, p));
	else if (key == SDLK_r)
		create_threads(camera_dir_helper(0, 0, p));
	else if (key == SDLK_f)
		create_threads(camera_dir_helper(0, 1, p));
	else if (key == SDLK_z)
		create_threads(camera_dir_helper(2, 0, p));
	else if (key == SDLK_c)
		create_threads(camera_dir_helper(2, 1, p));
	else
		camera_dir_2(key, p);
}
