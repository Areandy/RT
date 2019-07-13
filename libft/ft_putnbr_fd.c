/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 10:18:12 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/03 10:18:13 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnbr_fd(int a, int fd)
{
	if (a > 2147483647)
		return ;
	if (a == -2147483648)
	{
		ft_putstr_fd("-2147483648", fd);
		return ;
	}
	if (a < 0)
	{
		a *= -1;
		ft_putchar_fd('-', fd);
	}
	if (a < 10)
	{
		ft_putchar_fd(a + '0', fd);
		return ;
	}
	ft_putnbr_fd(a / 10, fd);
	ft_putchar_fd((a % 10) + '0', fd);
}
