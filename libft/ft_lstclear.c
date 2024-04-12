/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/27 17:28:32 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/29 21:01:51 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_clear(t_list **lst, void (*del)(void	*))
{
	if (!*lst)
		return ;
	_clear(&(*lst)->next, del);
	ft_lstdelone(*lst, del);
	*lst = 0;
}

void	ft_lstclear(t_list **lst, void (*del)(void	*))
{
	if (!lst || !del)
		return ;
	_clear(lst, del);
	lst = 0;
}
