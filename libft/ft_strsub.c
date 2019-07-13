/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 10:31:10 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 10:31:10 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strsub(char const *s, unsigned int start, size_t len)
{
	char *new;
	char *res;

	if (!s)
		return (0);
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	res = new;
	while (s[start] != '\0' && len--)
		*new++ = s[start++];
	*new = '\0';
	return (res);
}
