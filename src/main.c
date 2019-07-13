/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/15 10:35:15 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/15 10:35:21 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void			init(t_params *p)
{
	srand(time(NULL));
	if (SDL_Init(SDL_INIT_EVERYTHING) >= 0)
	{
		p->win_ptr = SDL_CreateWindow("Ray Trace", SDL_WINDOWPOS_CENTERED,
			SDL_WINDOWPOS_CENTERED, p->width, p->height, 0);
		p->surface = SDL_GetWindowSurface(p->win_ptr);
		p->pxls = p->surface->pixels;
	}
	TTF_Init();
	p->font = TTF_OpenFont("./resources/font/OpenSans-Bold.ttf", 14);
	if (p->font == NULL)
		exit(!(ft_putstr("Invalid font!\n")));
	p->color = (SDL_Color){255, 255, 255, 0};
	p->ui_window = IMG_Load("resources/ui.png");
	if (p->ui_window == NULL)
		exit(!(ft_putstr("Can't find file: resources/ui.png\n")));
	p->check_icon = IMG_Load("resources/check.png");
	if (p->check_icon == NULL)
		exit(!(ft_putstr("Can't find file: resources/check.png\n")));
	p->anaglyph = 0;
	p->antialiasing = 0;
	p->black = 0;
}

int				main(int ac, char **av)
{
	t_params		*params;
	SDL_Event		ev;

	if (ac == 2)
	{
		if (!(params = parser(av[1])))
			return (ft_putstr("\nThe file is invalid. Just like you.\n\n"));
	}
	else
		return (ft_putstr("\nusage: ./RT [scene_file.rt]\n\n"));
	params->tmp_i_d.id = 0;
	set_buttons(params);
	create_threads(params);
	while (1)
	{
		while (SDL_PollEvent(&ev) > 0)
			sdl_event(params, &ev);
	}
	return (1);
}
