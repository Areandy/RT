/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_htoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 12:31:18 by mlavreni          #+#    #+#             */
/*   Updated: 2019/01/05 12:31:24 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	to_hex(char c)
{
	if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= '0' && c <= '9')
		return (c - '0');
	return (0);
}

int			ft_htoi(const char *str)
{
	int		res;
	int		power;

	res = 0;
	power = ft_strlen(str);
	while (--power != -1 && to_hex(*str))
		res += to_hex(*str++) * ft_power(16, power);
	return (res);
}
