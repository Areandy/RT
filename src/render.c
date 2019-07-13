/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:35:02 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:35:03 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		pixel_view(int x, int y, int tmp, t_params *p)
{
	int		i;
	int		j;

	i = -1;
	if (p->pixel_view != 1)
		while (++i < p->pixel_view)
		{
			j = -1;
			while (++j < p->pixel_view)
				img_put_pixel(p, x + j, y + i, tmp);
		}
	else
		img_put_pixel(p, x, y, tmp);
}

t_vec		prepere_dir(int x, int y, t_params *p)
{
	float	u;
	float	v;
	t_vec	ray_dir;

	u = ((float)x + 0.5) / (float)p->width;
	v = ((float)y + 0.5) / (float)p->height;
	ray_dir = (t_vec)
	{
		(2.0 * u - 1.0) * p->fov * p->aspect_ratio,
		(1.0 - 2.0 * v) * p->fov,
		-1.0
	};
	rotate_xyz(&ray_dir, p);
	return (ray_dir);
}

void		render(int id, t_params *p)
{
	int		x;
	int		y;
	int		tmp;

	y = p->height / THREADS_AMOUNT * id;
	while (y < p->height / THREADS_AMOUNT * (id + 1))
	{
		x = 0;
		while (x < p->width)
		{
			if (check_ui(x, y))
			{
				x += p->pixel_view;
				continue ;
			}
			if (p->antialiasing)
				tmp = antialiasing(x, y, p);
			else
				tmp = get_color(ray_trace_2(p->camera->ori,
					prepere_dir(x, y, p), p->reflection_depth, p));
			pixel_view(x, y, tmp, p);
			x += p->pixel_view;
		}
		y += p->pixel_view;
	}
}

void		*prepere_render(void *thr)
{
	t_thread	*t;
	t_params	*p;

	t = (t_thread*)thr;
	if ((p = (t_params*)malloc(sizeof(t_params))))
	{
		*p = *t->p;
		render(t->id, p);
		free(p);
	}
	pthread_exit(0);
}

void		create_threads(t_params *p)
{
	int			i;
	t_thread	threads[THREADS_AMOUNT];

	if (p->anaglyph == 1)
		anaglyph_render(p);
	else
	{
		i = -1;
		while (++i < THREADS_AMOUNT)
		{
			threads[i].id = i;
			threads[i].p = p;
			pthread_create(&(threads[i].thread_id),
				NULL, prepere_render, &(threads[i]));
		}
		i = -1;
		while (++i < THREADS_AMOUNT)
			pthread_join(threads[i].thread_id, NULL);
	}
	render_ui(p);
}
