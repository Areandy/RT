/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:39:37 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:47:34 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	unsigned char	*str1;
	unsigned char	*str2;
	size_t			i;

	i = 0;
	str1 = (unsigned char*)dest;
	str2 = (unsigned char*)src;
	while (i < n)
	{
		str1[i] = str2[i];
		if (str2[i] == (unsigned char)c)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
