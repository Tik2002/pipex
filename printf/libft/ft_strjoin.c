/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 19:56:45 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 19:46:05 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	char	*str;
	size_t	str_len;

	if (!s1 || !s2)
	{
		return (0);
	}
	str_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	str = (char *)malloc(str_len);
	if (str)
	{
		ft_strlcpy(str, s1, str_len);
		ft_strlcat(str, s2, str_len);
	}
	return (str);
}
