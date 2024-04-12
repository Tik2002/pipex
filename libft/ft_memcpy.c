/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 19:43:02 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 18:43:12 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dst, const void *src, size_t n)
{
	char		*str;
	const char	*s;

	if (!dst && !src)
		return (0);
	str = dst;
	s = src;
	while (0 < n)
	{
		*str = *s;
		str++;
		s++;
		n--;
	}
	return (dst);
}
