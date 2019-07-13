/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:20:28 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 11:35:13 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

void			set_obj_arr(t_params *p)
{
	int			i;

	i = -1;
	while (++i < p->obj_amount)
	{
		p->obj_arr[i].center = (t_vec){-422.0, -422.0, -422.0};
		p->obj_arr[i].dir = (t_vec){0.0, 1.0, 0.0};
		p->obj_arr[i].normal = (t_vec){0.0, 1.0, 0.0};
		p->obj_arr[i].angle = 0.0;
		p->obj_arr[i].radius = 0.0;
		p->obj_arr[i].height = -1;
		p->obj_arr[i].height_up = -1;
		p->obj_arr[i].height_down = 0;
		p->obj_arr[i].color = (t_color){255.0, 255.0, 255.0};
		p->obj_arr[i].specular = 0.0;
		p->obj_arr[i].reflection = 0.0;
		p->obj_arr[i].k = 5.0;
		p->obj_arr[i].slice_type = 1;
		p->obj_arr[i].slice_ori = (t_vec){-422.0, -422.0, -422.0, 0.0};
		p->obj_arr[i].slice_dir = (t_vec){0.0, 0.0, 0.0, 0.0};
		p->obj_arr[i].texture = NULL;
	}
}

int				find_obj_arr(int fd, t_params *p)
{
	int			rat;
	int			amount;
	char		*line;
	t_obj		*obj_arr;
	t_pokemon	*pokemons;

	pokemons = set_pokemons();
	while ((rat = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "OBJECTS") == line)
		{
			if (!(helper(&amount, 7, line)))
				break ;
			if (!(obj_arr = (t_obj*)malloc(sizeof(t_obj) * amount)))
				return (0);
			p->obj_arr = obj_arr;
			p->obj_amount = amount;
			free(line);
			set_obj_arr(p);
			return (whos_that_pokemon(fd, pokemons, p));
		}
		free(line);
	}
	free(line);
	return (0);
}

void			set_params(t_params *p)
{
	if (p->width < 500 || p->width > 2000)
		p->width = 500;
	if (p->height < 500 || p->height > 1300)
		p->height = 500;
	if (p->fov < 50 || p->fov > 130)
		p->fov = 70;
	init(p);
	p->fov = tan(p->fov / 2 * M_PI / 180);
	p->aspect_ratio = (float)p->width / (float)p->height;
	p->pixel_view = 1;
	if (p->reflection_depth < 0)
		p->reflection_depth = 0;
	else if (p->reflection_depth > 30)
		p->reflection_depth = 30;
}

int				check_the_file(char *file)
{
	int			rat;
	int			fd;
	char		*line;
	static int	cux[3] = {0, 0, 0};

	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	while ((rat = get_next_line(fd, &line)) > 0)
	{
		if (ft_strstr(line, "PARAMS")
		&& !(cux[1]) && !(cux[2]))
			cux[0] = 1;
		else if (ft_strstr(line, "OBJECTS")
		&& cux[0] && !(cux[2]))
			cux[1] = 1;
		else if (ft_strstr(line, "LIGHT_SOURCES")
		&& cux[0] && cux[1])
			cux[2] = 1;
		free(line);
	}
	close(fd);
	if (cux[0] && cux[1] && cux[2] && rat != -1)
		return (1);
	return (0);
}

t_params		*parser(char *file)
{
	int			fd;
	t_params	*p;

	p = NULL;
	if (!(check_the_file(file)))
		return (0);
	if (!(p = (t_params*)(malloc(sizeof(t_params)))))
		return (0);
	if (!(p->camera = (t_camera*)malloc(sizeof(t_camera))))
		return (0);
	if ((fd = open(file, O_RDONLY)) == -1)
		return (0);
	p->obj_arr = NULL;
	p->light_sources = NULL;
	if (!(get_params(fd, p)))
		return (ultimate_cleaner(p, 0));
	if (!(find_obj_arr(fd, p)))
		return (ultimate_cleaner(p, 1));
	if (!(get_light_sources(fd, p)))
		return (ultimate_cleaner(p, 2));
	set_params(p);
	return (p);
}
