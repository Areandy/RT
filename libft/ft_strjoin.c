/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:41:02 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 11:41:03 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *new;
	char *res;

	if (s1 && !s2)
		return ((res = ft_strdup(s1)));
	else if (!s1 && s2)
		return ((res = ft_strdup(s2)));
	else if (!s1 && !s2)
		return (NULL);
	if (!(new = (char *)malloc(sizeof(char)
		* (ft_strlen(s1) + ft_strlen(s2) + 1))))
		return (0);
	res = new;
	while (*s1)
		*new++ = *s1++;
	while (*s2)
		*new++ = *s2++;
	*new = '\0';
	return (res);
}
