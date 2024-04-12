/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/31 01:17:11 by senate            #+#    #+#             */
/*   Updated: 2024/02/24 19:38:14 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putnbr_base(unsigned int nbr, const char *base, size_t len)
{
	if (nbr < len)
		return (ft_putchar(base[nbr]));
	return (ft_putnbr_base(nbr / len, base, len)
		+ ft_putnbr_base(nbr % len, base, len));
}
