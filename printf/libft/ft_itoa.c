/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 20:16:45 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/27 18:42:46 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	_count(int n)
{
	int	i;

	i = 0;
	if (n < 0)
		i++;
	else if (n == 0)
		return (1);
	while (n)
	{
		n /= 10;
		i++;
	}
	return (i);
}

char	*ft_itoa(int n)
{
	int		i;
	char	*arr;
	int		count;

	if (n == -2147483648)
		return (ft_strdup("-2147483648"));
	i = 0;
	count = _count(n);
	arr = (char *)malloc(count + 1);
	if (!arr)
		return (0);
	arr[count] = '\0';
	if (n < 0)
	{
		arr[i] = '-';
		i++;
		n *= -1;
	}
	while (i < count)
	{
		count--;
		arr[count] = n % 10 + '0';
		n /= 10;
	}
	return (arr);
}
