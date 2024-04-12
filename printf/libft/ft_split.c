/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 21:57:21 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 21:01:19 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static void	_pass_del(char const **s, char del)
{
	while (**s == del && **s)
		(*s)++;
}

static size_t	_len(char const **s, char del)
{
	size_t	len;

	len = 0;
	while (**s && **s != del)
	{
		(*s)++;
		len++;
	}
	return (len);
}

static size_t	_word_count(char const *s, char del)
{
	size_t	count;
	int		flag;

	count = 0;
	flag = 0;
	_pass_del(&s, del);
	while (*s)
	{
		if (*s != del)
			flag = 1;
		else if (*s == del && flag)
		{
			count++;
			flag = 0;
		}
		s++;
	}
	return (count + flag);
}

static char	**_all(char const *s, char del, size_t count)
{
	char	*p;
	char	**str;
	size_t	len;
	size_t	i;

	i = 0;
	str = (char **)malloc((count + 1) * sizeof(char *));
	if (!str)
		return (0);
	str[count] = 0;
	while (i < count)
	{
		_pass_del(&s, del);
		p = (char *)s;
		len = _len(&s, del);
		str[i] = (char *)malloc(len + 1);
		ft_strlcpy(str[i], p, len + 1);
		i++;
	}
	return (str);
}

char	**ft_split(char const *s, char c)
{
	if (!s)
		return (0);
	return (_all(s, c, _word_count(s, c)));
}
