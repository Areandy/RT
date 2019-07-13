/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_light_sources.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:01:54 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 11:01:55 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void		set_default_light_sources(t_params *p)
{
	int		i;

	i = -1;
	while (++i < p->light_amount)
	{
		p->light_sources[i].ori = (t_vec){-422, -422, -422};
		p->light_sources[i].dir = (t_vec){0.0, 1.0, 0.0};
		p->light_sources[i].intensity = 0.0;
		p->light_sources[i].type = 1;
	}
}

int			light_type_checker(int type)
{
	if (type > 0 && type < 4)
		return (1);
	return (0);
}

int			get_light(char *line, int *amount, int *i, t_params *p)
{
	if (ft_strstr(line, "\t\t_origin: "))
	{
		p->light_sources[*amount].ori = get_vec(line + 10);
		p->light_sources[*amount].ori += to_vec(0.01);
	}
	else if (ft_strstr(line, "\t\t_intensity: "))
		p->light_sources[*amount].intensity = fabs(ft_atof(line + 13));
	else if (ft_strstr(line, "\t\t_dir: "))
		p->light_sources[*amount].dir = get_vec(line + 7);
	else if (ft_strstr(line, "\t\t_type: ")
				&& light_type_checker(abs(ft_atoi(line + 8))))
		p->light_sources[*amount].type = abs(ft_atoi(line + 8));
	else if (ft_strncmp(line, "\0", 1) == 0)
		;
	else if (ft_strstr(line, "\tlight{"))
	{
		*amount += 1;
		*i = -1;
	}
	else
		return (0);
	return (1);
}

int			get_light_sources(int fd, t_params *p)
{
	int		rat;
	int		res;
	char	*line;
	int		amount;

	while ((rat = get_next_line(fd, &line)) > 0)
	{
		if (ft_strncmp(line, "LIGHT_SOURCES", 13) == 0)
		{
			if (!(helper(&amount, 13, line)))
				break ;
			create_lights(amount, p);
			while ((amount = prepere_light(fd, p)) > 0)
				res = amount;
			if (res != p->light_amount || amount == -2)
				return (cleaner(line, 0));
			return (cleaner(line, 1));
		}
		free(line);
	}
	return (cleaner(line, 0));
}
