/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:48:33 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:52:38 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	unsigned char	*str;
	size_t			i;
	unsigned char	x;

	str = (unsigned char*)s;
	i = 0;
	x = (unsigned char)c;
	while (i < n)
	{
		if (str[i] == x)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
