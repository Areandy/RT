/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_power.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/06 14:33:52 by mlavreni          #+#    #+#             */
/*   Updated: 2019/01/06 14:33:55 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_power(int nbr, int power)
{
	int	tmp;

	tmp = nbr;
	if (power == 0)
		return (1);
	if (power == 1)
		return (nbr);
	while (--power)
		nbr *= tmp;
	return (nbr);
}
