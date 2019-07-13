/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 12:08:43 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/04 16:12:17 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_atoi(const char *str)
{
	int		i;
	int		tmp;
	int		res;
	int		negative;

	i = 0;
	tmp = 0;
	res = 0;
	while (str[i] == '\n' || str[i] == ' ' || str[i] == '\t'
		|| str[i] == '\r' || str[i] == '\f' || str[i] == '\v')
		i++;
	negative = str[i] == '-' ? -1 : 1;
	if (str[i] == '+' || str[i] == '-')
		i++;
	while (str[i] >= '0' && str[i] <= '9')
	{
		res = (res * 10) + (str[i++] - '0');
		res != 0 ? tmp++ : 0;
	}
	if (tmp > 19 && negative == -1)
		return (0);
	if (tmp > 19 && negative == 1)
		return (-1);
	return (res * negative);
}
