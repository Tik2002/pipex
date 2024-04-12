/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:32:50 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/29 21:02:01 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*new;
	t_list	*node;

	if (!lst || !f || !del)
		return (0);
	new = ft_lstnew(f(lst->content));
	if (!new)
		return (0);
	node = new;
	while (lst->next)
	{
		new->next = ft_lstnew(f(lst->next->content));
		if (!new)
		{
			ft_lstclear(&node, del);
			return (0);
		}
		lst = lst->next;
		new = new->next;
	}
	return (node);
}
