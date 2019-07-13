/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 16:06:51 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 16:07:40 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char *str1;
	const unsigned char *str2;

	str1 = s1;
	str2 = s2;
	while (n--)
		if (*str1++ != *str2++)
			return (*(str1 - 1) - *(str2 - 1));
	return (0);
}
