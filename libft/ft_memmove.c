/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:53:04 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:53:32 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*d;
	const char	*s;
	const char	*temp1;
	char		*temp2;

	d = dest;
	s = (char *)src;
	if (d < s)
		while (n--)
			*d++ = *s++;
	else
	{
		temp1 = s + (n - 1);
		temp2 = d + (n - 1);
		while (n--)
			*temp2-- = *temp1--;
	}
	return (dest);
}
