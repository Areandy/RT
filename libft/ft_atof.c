/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atof.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/02/21 11:34:00 by mlavreni          #+#    #+#             */
/*   Updated: 2019/02/21 11:34:00 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

double		ft_atof(char *str)
{
	double	res;
	double	f;
	double	tmp;

	res = 0;
	f = 1;
	tmp = (double)ft_atoi(str);
	while (*str == 32 || (*str >= 9 && *str <= 13))
		str++;
	if (*str == '-')
		str++;
	str += ft_decimal_length(tmp);
	if (*str != '.')
		return (tmp);
	str++;
	while (*str && ft_isdigit(*str))
	{
		f /= 10;
		res += (*str - '0') * f;
		str++;
	}
	tmp += (tmp >= 0) ? res : -res;
	return (tmp);
}
