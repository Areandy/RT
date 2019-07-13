/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstiter.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:33:08 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/03 14:33:09 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstiter(t_list *lst, void (*f)(t_list *elem))
{
	t_list *current;

	if (lst && f)
	{
		current = lst;
		while (current != NULL)
		{
			f(current);
			current = current->next;
		}
	}
}
