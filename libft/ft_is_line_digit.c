/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_is_line_digit.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 17:37:10 by mlavreni          #+#    #+#             */
/*   Updated: 2019/01/06 17:37:18 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_is_line_digit(char const *line)
{
	while (*line)
	{
		if (!(ft_isdigit(*line)) && *line != '-')
			return (0);
		line++;
	}
	return (1);
}
