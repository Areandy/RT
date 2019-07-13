/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_light_funcs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/04/09 13:15:37 by mlavreni          #+#    #+#             */
/*   Updated: 2019/04/09 13:54:11 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			prepere_light(int fd, t_params *p)
{
	int			rat;
	char		*line;
	static int	amount = -1;
	int			i;

	i = 0;
	while ((rat = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "\t}") == line)
			return (cleaner(line,
			(i != 3) ? -2 : amount + 1));
		else if (ft_strncmp(line, "}", 1) == 0)
			return (cleaner(line, -1));
		else if (!(get_light(line, &amount, &i, p)))
			break ;
		free(line);
		i++;
		if (amount + 1 > p->light_amount)
			return (-2);
	}
	return (cleaner(line, -1));
}

void		create_lights(int amount, t_params *p)
{
	t_light	*lights;

	if (!(lights = (t_light*)malloc(sizeof(t_light) * amount)))
		exit(0);
	p->light_sources = lights;
	p->light_amount = amount;
	set_default_light_sources(p);
}

t_color		color_checker(t_color clr)
{
	int			i;

	i = -1;
	while (++i < 3)
	{
		if (clr[i] < 0.0)
			clr[i] = 0.0;
		else if (clr[i] > 255.0)
			clr[i] = 255.0;
	}
	return (clr);
}
