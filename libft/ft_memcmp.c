/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/18 20:52:38 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 20:08:43 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_memcmp(const void *s1, const void *s2, size_t n)
{
	const unsigned char	*p1;
	const unsigned char	*p2;

	p1 = s1;
	p2 = s2;
	if (n == 0)
		return (0);
	while ((*p1 == *p2) && n > 1)
	{
		p1++;
		p2++;
		n--;
	}
	return (*p1 - *p2);
}
