/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_count_words.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 13:43:38 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/06 13:43:39 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_count_words(char const *s, char c)
{
	int i;
	int count;
	int flag;

	i = 0;
	count = 0;
	flag = 1;
	while (s[i] && flag)
	{
		flag = 0;
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
			flag = 1;
		while (s[i] != c && s[i])
			i++;
		if (flag)
			count++;
	}
	return (count);
}
