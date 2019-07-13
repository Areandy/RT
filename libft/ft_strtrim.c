/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 11:57:27 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 11:57:28 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	char	*new;
	int		i;
	int		len;

	if (!s)
		return (0);
	i = -1;
	len = ft_strlen(s);
	while (s[len - 1] == ' ' || s[len - 1] == '\n' || s[len - 1] == '\t')
		len--;
	while (s[++i] == ' ' || s[i] == '\n' || s[i] == '\t')
		len--;
	if (len < 0)
		len = 0;
	if (!(new = (char *)malloc(sizeof(char) * (len + 1))))
		return (0);
	s += i;
	i = -1;
	while (++i < len)
		new[i] = *s++;
	new[i] = '\0';
	return (new);
}
