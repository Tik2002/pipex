/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/04/12 05:00:17 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

int	main(int ac, char **av)
{
	int fd[2];
	int i = 0;
	while (i < 2)
	{
		if (!i)
		{
			int x;
			scanf("%d", &x);
			write(fd[1], &x, sizeof(int));
		}
		else
		{
			close (fd[1]);
			int y;
			read(fd[0], &y, sizeof(int));
			printf("%d\n", y);
		}
		i++;
	}

	// int id = fork();
	// int n;

	// if (!id)
	// 	n = 1;
	// else
	// 	n = 6;
	// if (id)
	// 	wait();
	// int i;
	// for (i = n; i < n + 5; i++)
	// {
	// 	ft_printf("%d ", i);
	// 	fflush(stdout);
	// }
	// if (!id)
	// 	ft_printf("child proc\n");
	// else
	// 	ft_printf("parent proc\n");
	return (0);
}
