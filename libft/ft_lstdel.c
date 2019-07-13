/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:31:57 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/03 14:31:58 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstdel(t_list **alst, void (*del)(void *, size_t))
{
	t_list *current;

	if (alst && del)
	{
		current = *alst;
		while (current != NULL)
		{
			del(current->content, current->content_size);
			free(current);
			current = current->next;
		}
		*alst = NULL;
	}
}
