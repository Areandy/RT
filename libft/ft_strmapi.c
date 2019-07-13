/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 09:46:04 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 09:46:05 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*new;
	char	*res;
	int		i;

	if (s && f)
	{
		if (!(new = (char *)malloc(sizeof(char) * (ft_strlen(s) + 1))))
			return (0);
		i = 0;
		res = new;
		while (*s)
			*new++ = f(i++, *s++);
		*new = '\0';
		return (res);
	}
	return (0);
}
