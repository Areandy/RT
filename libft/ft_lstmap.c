/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mlavreni <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/03 14:33:38 by mlavreni          #+#    #+#             */
/*   Updated: 2018/11/03 14:33:38 by mlavreni         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list		*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list		*new;
	t_list		*current;

	if (!lst || !f)
		return (NULL);
	current = f(lst);
	new = current;
	while (lst->next)
	{
		lst = lst->next;
		if (!(current->next = f(lst)))
		{
			free(current->next);
			return (NULL);
		}
		current = current->next;
	}
	return (new);
}
