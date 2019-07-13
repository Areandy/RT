/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gimy_gimy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:19:05 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 11:19:06 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

int			check_vec(t_vec v)
{
	int		i;

	i = -1;
	while (++i < 3)
	{
		if (v[i] == -422.0)
			return (0);
	}
	return (1);
}

t_vec		get_vec(char *str)
{
	t_vec	res;

	res = (t_vec){-422.0, -422.0, -422.0};
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	while (*str == '{')
	{
		str++;
		res[0] = ft_atof(str);
		if (ft_strchr(str, ','))
			str = ft_strchr(str, ',') + 1;
		else
			break ;
		res[1] = ft_atof(str);
		if (ft_strchr(str, ','))
			str = ft_strchr(str, ',') + 1;
		else
			break ;
		res[2] = ft_atof(str);
		return (res);
	}
	ft_putstr("Warning: invalid vector set to default\n");
	return ((t_vec){0.0, 0.0, 0.0});
}

int			get_camera(char *line, t_params *p)
{
	if (ft_strstr(line, "\t_camera->ori: "))
		p->camera->ori = get_vec(line + 14);
	else if (ft_strstr(line, "\t_camera->dir: "))
		p->camera->dir = get_vec(line + 14);
	else
		return (0);
	return (1);
}

int			get_params(int fd, t_params *p)
{
	int		rat;
	char	*line;
	int		i;

	i = -1;
	while ((rat = get_next_line(fd, &line)) > 0)
	{
		if (ft_strchr(line, '}') == line)
			return (cleaner(line, (i != 6) ? 0 : 1));
		else if (ft_strstr(line, "\t_width: "))
			p->width = ft_atoi(line + 8);
		else if (ft_strstr(line, "\t_height: "))
			p->height = ft_atoi(line + 9);
		else if (ft_strstr(line, "\t_fov: "))
			p->fov = ft_atoi(line + 6);
		else if (ft_strstr(line, "\t_reflection_depth: "))
			p->reflection_depth = ft_atoi(line + 20);
		else if (ft_strstr(line, "PARAMS{"))
			;
		else if (!(get_camera(line, p)))
			break ;
		free(line);
		i++;
	}
	return (cleaner(line, 0));
}
