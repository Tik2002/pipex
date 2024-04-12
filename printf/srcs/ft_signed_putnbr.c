/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_signed_putnbr.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 02:11:57 by senate            #+#    #+#             */
/*   Updated: 2024/02/24 19:34:46 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_signed_putnbr(long long n)
{
	if (n < 0)
	{
		return (ft_putchar('-') + ft_putnbr_base(-n, "0123456789", 10));
	}
	return (ft_putnbr_base(n, "0123456789", 10));
}
