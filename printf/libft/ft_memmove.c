/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 20:27:43 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 19:17:55 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int	i;

	i = 0;
	if (!dst && !src)
		return (dst);
	if (src < dst)
	{
		i = len - 1;
		while (i >= 0)
		{
			((char *const)dst)[i] = ((char *const)src)[i];
			i--;
		}
	}
	else
		ft_memcpy(dst, src, len);
	return (dst);
}
