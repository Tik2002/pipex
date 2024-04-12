/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:37:48 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 18:40:23 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memset(void *s, int c, size_t len)
{
	unsigned char	*p;
	size_t			i;

	p = s;
	i = 0;
	while (len > 0)
	{
		p[i] = (unsigned char)c;
		i++;
		len--;
	}
	return (s);
}
