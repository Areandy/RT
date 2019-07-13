/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:28:41 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 09:28:42 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmap(char const *s, char (*f)(char))
{
	char *new;
	char *res;

	if (s && f)
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (0);
		res = new;
		while (*s)
			*new++ = f(*s++);
		*new = '\0';
		return (res);
	}
	return (0);
}
