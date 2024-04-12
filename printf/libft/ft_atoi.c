/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/24 16:57:58 by tigpetro          #+#    #+#             */
/*   Updated: 2024/01/26 20:56:44 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_atoi(const char *str)
{
	int	i;
	int	negativ;
	int	buff;

	i = 0;
	negativ = 1;
	buff = 0;
	while (str[i] == ' ' || str[i] == '\f' || str[i] == '\n'
		|| str[i] == '\r' || str[i] == '\t'
		|| str[i] == '\v')
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			negativ = -negativ;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		buff = buff * 10 + (str[i] - '0');
		i++;
	}
	return (buff * negativ);
}
