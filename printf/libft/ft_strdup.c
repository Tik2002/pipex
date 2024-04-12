/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 17:40:01 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/24 17:45:24 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	unsigned int	i;
	unsigned int	l;
	char			*cpy;

	i = 0;
	l = 0;
	if (!*s1)
		cpy = 0;
	while (s1[i])
		i++;
	cpy = (char *)malloc((i + 1) * sizeof(char));
	if (cpy == 0)
		return (0);
	while (l <= i)
	{
		cpy[l] = s1[l];
		l++;
	}
	return (cpy);
}
