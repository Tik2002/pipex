/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_base_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/02 18:35:30 by tigpetro          #+#    #+#             */
/*   Updated: 2024/02/24 19:36:11 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_putnbr_base_ptr(unsigned long long nbr, const char *base, size_t len)
{
	if (nbr < len)
		return (write(1, base + nbr, 1));
	return (ft_putnbr_base_ptr(nbr / len, base, len)
		+ ft_putnbr_base_ptr(nbr % len, base, len));
}
