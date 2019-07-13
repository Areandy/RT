/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleaners.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:00:45 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 11:00:46 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			cleaner(char *line, int ret)
{
	free(line);
	return (ret);
}

void		check_texture(t_params *p)
{
	int		i;

	i = -1;
	while (++i < p->obj_amount)
		if (p->obj_arr[i].texture != NULL)
			SDL_FreeSurface(p->obj_arr[i].texture);
}

t_params	*ultimate_cleaner(t_params *p, int flag)
{
	free(p->camera);
	if (flag >= 1 && p->obj_arr != NULL)
	{
		check_texture(p);
		free(p->obj_arr);
	}
	if (flag >= 2 && p->light_sources != NULL)
		free(p->light_sources);
	free(p);
	return (0);
}

int			helper(int *amount, int size, char *line)
{
	if (*(line + size) == '[')
	{
		*amount = ft_atoi(line + size + 1);
		if (*amount < 1 || *amount > 50)
			return (0);
	}
	else
		return (0);
	return (1);
}
