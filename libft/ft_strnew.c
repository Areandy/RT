/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/30 16:26:27 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/30 16:26:28 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *res;

	if (!(res = (char*)malloc(sizeof(char) * (size + 1))))
		return (0);
	ft_bzero(res, size + 1);
	return (res);
}
