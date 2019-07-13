/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:42:40 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:47:44 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char		*str1;
	unsigned char		*str2;
	size_t				i;

	str1 = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	i = 0;
	while (i < n)
	{
		str1[i] = str2[i];
		i++;
	}
	return (dest);
}
