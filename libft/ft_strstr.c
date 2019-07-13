/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 13:55:47 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 13:55:52 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *s1, const char *s2)
{
	size_t i;
	size_t j;

	if (*s2 == '\0')
		return ((char*)s1);
	i = 0;
	while (s1[i] != '\0')
	{
		j = 0;
		while (s2[j] == s1[i + j])
		{
			if (s2[j + 1] == '\0')
				return ((char*)&s1[i]);
			j++;
		}
		i++;
	}
	return (0);
}
