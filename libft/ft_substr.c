/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 18:58:15 by tigpetro          #+#    #+#             */
/*   Updated: 2024/02/19 18:41:19 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_minimal(size_t a, size_t b)
{
	if (a < b)
		return (a);
	return (b);
}

static char	*_all_null(void)
{
	char	*str;

	str = (char *)malloc(1);
	if (!str)
		return (0);
	*str = '\0';
	return (str);
}

static char	*_all(const char *s, size_t len)
{
	char	*str;

	str = (char *)malloc(len + 1);
	if (str == 0)
		return (0);
	ft_strlcpy(str, s, len + 1);
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	if (!s)
	{
		return (0);
	}
	if (start > ft_strlen(s))
	{
		return (_all_null());
	}
	return (_all(s + start, _minimal(len, ft_strlen(s) - start)));
}
