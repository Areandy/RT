/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:14:47 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:15:04 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *str, int c)
{
	char	x;
	char	*res;
	int		i;

	x = (char)c;
	res = NULL;
	i = 0;
	if (c == '\0' || c == 256)
		return ((char*)&str[ft_strlen(str)]);
	while (str[i] != '\0')
	{
		if (str[i] == x)
		{
			res = (char*)&str[i];
			return (res);
		}
		i++;
	}
	return (NULL);
}
