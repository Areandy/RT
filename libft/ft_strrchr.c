/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:56:35 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:57:07 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	char	x;
	char	*res;
	int		i;

	res = NULL;
	i = ft_strlen(str);
	x = (char)c;
	while (i >= 0)
	{
		if (str[i] == x)
		{
			res = (char*)&str[i];
			return (res);
		}
		i--;
	}
	return (NULL);
}
