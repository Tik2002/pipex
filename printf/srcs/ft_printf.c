/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/30 20:00:27 by senate            #+#    #+#             */
/*   Updated: 2024/02/21 18:38:53 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>

int	ft_printf(const char *prm, ...)
{
	va_list	args;
	int		len;

	len = 0;
	va_start(args, prm);
	while (*prm)
	{
		if (*prm == '%')
		{
			prm++;
			if (ft_checker(*prm))
			{
				len += ft_print(args, prm);
				prm++;
			}
		}
		if (*prm != '%' && *prm)
		{
			len += ft_putchar(*prm);
			prm++;
		}
	}
	va_end(args);
	return (len);
}

// int main()
// {
// 	int i;
// 	i = ft_printf("\001\002\007\v\010\f\r\n");
// 	printf("%d\n", i);
// 	printf("JUJ");
// 	i = printf("\001\002\007\v\010\f\r\n");
// 	printf("%d\n", i);
// 	return (0);
// }
