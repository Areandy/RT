/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pokemons.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 10:58:38 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 10:58:43 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "parser.h"

t_pokemon	*set_pokemons(void)
{
	static t_pokemon	pokemons[5] = {
		{"\tsphere{", shpere_hit, sphere_normal},
		{"\tcylinder{", cylinder_hit, cylinder_normal},
		{"\tcone{", cone_hit, cone_normal},
		{"\tplane{", plane_hit, plane_normal},
		{"\tparaboloid{", parabl_hit, parabl_normal}
	};

	return (pokemons);
}

int			whos_that_pokemon(int fd, t_pokemon *poks, t_params *p)
{
	int			rat;
	char		*line;
	static int	amount = -1;
	int			i;

	while ((rat = get_next_line(fd, &line)) > 0)
	{
		i = -1;
		if (ft_strstr(line, "}") == line)
			return (cleaner(line, (amount + 1 != p->obj_amount) ? 0 : 1));
		while (++i < 5)
		{
			if (ft_strncmp(line, poks[i].shape, 20) == 0)
			{
				if (++amount + 1 > p->obj_amount)
					return (cleaner(line, 0));
				if (!(add_obj(&p->obj_arr[amount], poks[i], fd)))
					return (cleaner(line, 0));
				break ;
			}
		}
		free(line);
	}
	return (cleaner(line, 0));
}
