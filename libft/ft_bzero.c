/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/10/25 15:37:43 by mlavreni          #+#    #+#             */
/*   Updated: 2018/10/25 15:48:05 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_bzero(void *dst, size_t len)
{
	size_t				i;
	unsigned char		*str;

	i = 0;
	str = (unsigned char*)dst;
	while (i < len)
		str[i++] = '\0';
}
