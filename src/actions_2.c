/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions_2.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/15 14:32:11 by mlavreni          #+#    #+#             */
/*   Updated: 2019/05/15 14:32:12 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		name_screen(char *str, char *tmp, struct tm tm)
{
	tmp = ft_itoa(tm.tm_year + 1900);
	strcat(str, tmp);
	free(tmp);
	strcat(str, "-");
	tmp = ft_itoa(tm.tm_mon + 1);
	strcat(str, tmp);
	free(tmp);
	strcat(str, "-");
	tmp = ft_itoa(tm.tm_mday);
	strcat(str, tmp);
	free(tmp);
	strcat(str, " at ");
	tmp = ft_itoa(tm.tm_hour);
	strcat(str, tmp);
	free(tmp);
	strcat(str, ".");
	tmp = ft_itoa(tm.tm_min);
	strcat(str, tmp);
	free(tmp);
	strcat(str, ".");
	tmp = ft_itoa(tm.tm_sec);
	strcat(str, tmp);
	free(tmp);
	strcat(str, ".png");
}

void		screen_shot(t_params *p)
{
	SDL_Surface		*screen;
	char			*str;
	time_t			t;
	struct tm		tm;
	char			*tmp;

	t = time(NULL);
	tmp = NULL;
	tm = *localtime(&t);
	str = malloc(sizeof(char) * 100);
	strcat(str, "Screen Shot ");
	name_screen(str, tmp, tm);
	screen = surface_cpy(p->surface);
	IMG_SavePNG(screen, str);
	free(str);
	SDL_FreeSurface(screen);
}

int			key_press(SDL_Keycode key, t_params *p)
{
	if (key == SDLK_ESCAPE)
		exit(1);
	else if (key == SDLK_w)
		create_threads(camera_move(0, p));
	else if (key == SDLK_s)
		create_threads(camera_move(1, p));
	else if (key == SDLK_a)
		create_threads(camera_move(3, p));
	else if (key == SDLK_d)
		create_threads(camera_move(2, p));
	else if (key == SDLK_t)
		create_threads(camera_down_up(1, p));
	else if (key == SDLK_g)
		create_threads(camera_down_up(0, p));
	else if (key == SDLK_p)
	{
		p->pixel_view = (p->pixel_view == 1) ? 10 : 1;
		create_threads(p);
	}
	else if (key == SDLK_0)
		screen_shot(p);
	else
		camera_dir(key, p);
	return (1);
}
