/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:53:53 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:54:16 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *destination, int c, size_t n)
{
	size_t			i;
	unsigned char	*res;

	i = 0;
	res = (unsigned char*)destination;
	while (i < n)
		res[i++] = (unsigned char)c;
	return (destination);
}
