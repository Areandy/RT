/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sdl_funcs.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vprypesh <vprypesh@student.unit.ua>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 18:43:10 by vprypesh          #+#    #+#             */
/*   Updated: 2019/05/02 18:43:11 by vprypesh         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/rtv1.h"

void		render_text(t_params *p, char *str, int x, int y)
{
	SDL_Surface	*text;
	SDL_Rect	message_rect;

	message_rect = (SDL_Rect){x, y, 100, 100};
	if (TTF_Init() != 0)
	{
		ft_putstr("FAIL TO LOAD TTF\n");
		exit(0);
	}
	if (p->font == NULL)
	{
		ft_putstr("FAIL TO LOAD FONT!\n");
		exit(0);
	}
	text = TTF_RenderText_Solid(p->font, str, p->color);
	p->surface->locked = 0;
	SDL_BlitSurface(text, NULL, p->surface, &message_rect);
	SDL_FreeSurface(text);
	SDL_UpdateWindowSurface(p->win_ptr);
}
