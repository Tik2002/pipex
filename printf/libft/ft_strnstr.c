/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 21:28:27 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 21:03:03 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *haystack, const char *needle, size_t len)
{
	size_t	hs_len;
	size_t	nd_len;
	size_t	i;

	if ((!haystack || !needle) && !len)
		return (0);
	hs_len = ft_strlen(haystack);
	nd_len = ft_strlen(needle);
	i = 0;
	if (!*needle)
		return ((char *)haystack);
	while (haystack[i] != '\0' && i + nd_len <= (len))
	{
		if (nd_len + i <= hs_len && !ft_strncmp((haystack + i), needle, nd_len))
			return ((char *)(haystack + i));
		i++;
	}
	return (0);
}
