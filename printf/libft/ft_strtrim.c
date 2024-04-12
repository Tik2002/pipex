/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 20:33:31 by tigpetro          #+#    #+#             */
/*   Updated: 2024/02/19 18:42:51 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_cut(const char *str, char **left, char **right, const char *set)
{
	while (ft_strchr(set, **left) && (*left < *right))
		(*left)++;
	while (ft_strchr(set, **right) && (*right != str))
		(*right)--;
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

static char	*_all(char *str, size_t len)
{
	char	*newstr;

	newstr = (char *)malloc(len);
	if (newstr)
		ft_strlcpy(newstr, str, len);
	return (newstr);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*left;
	char	*right;

	if (!set)
	{
		return ((char *)s1);
	}
	if (!s1)
	{
		return (0);
	}
	left = (char *)s1;
	right = (char *)s1 + ft_strlen(s1) - 1;
	_cut(s1, &left, &right, set);
	if (left > right)
		return (_all_null());
	return (_all(left, right - left + 2));
}
