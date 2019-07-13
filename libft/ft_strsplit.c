/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/31 13:06:28 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/31 13:06:29 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char			**ft_strsplit(char const *s, char c)
{
	char	**res;
	int		i;
	int		j;
	int		k;

	if (!s || !(res = (char **)malloc(sizeof(char*) *
		(ft_count_words(s, c) + 1))))
		return (NULL);
	i = -1;
	j = 0;
	while (++i < ft_count_words(s, c))
	{
		k = 0;
		if (!(res[i] = ft_strnew(ft_get_word_len(&s[j], c))))
			res[i] = NULL;
		while (s[j] == c)
			j++;
		while (s[j] != c && s[j])
			res[i][k++] = s[j++];
		res[i][k] = '\0';
	}
	res[i] = 0;
	return (res);
}
