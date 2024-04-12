/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 18:16:45 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 19:37:17 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t	dst_len;
	size_t	src_len;
	size_t	i;

	dst_len = 0;
	i = 0;
	if ((!dst || !src) && !dstsize)
		return (0);
	while (dst[dst_len] != '\0' && dst_len < dstsize)
		dst_len++;
	src_len = ft_strlen(src);
	if (dst_len < dstsize)
	{
		while (src[i] != '\0' && (dst_len + i) < dstsize - 1)
		{
			dst[dst_len + i] = src[i];
			i++;
		}
		dst[dst_len + i] = '\0';
	}
	return (src_len + dst_len);
}
