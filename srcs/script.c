/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   script.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:51:18 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/25 20:51:26 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_destroy_for_script(t_pipex *pip, int index)
{
	int	i;

	i = 0;
	while (pip->cmds[index][i])
		free(pip->cmds[index][i++]);
	free(pip->cmds[index]);
}

void	malloc_script(t_pipex *pip, int index)
{
	int		i;
	int		size;
	int		j;

	size = 0;
	while (pip->cmds[index][size])
		size++;
	pip->script = (char **)malloc(sizeof(char *) * (++size + 1));
	if (!pip->script)
	{
		perror("pipex");
		destroy(pip);
		exit(1);
	}
	pip->script[size] = 0;
	i = 0;
	pip->script[i++] = ft_strdup("/bin/bash");
	pip->script[i++] = ft_strdup(pip->cmds[index][0]);
	j = 1;
	while (i < size)
		pip->script[i++] = ft_strdup(pip->cmds[index][j++]);
	_destroy_for_script(pip, index);
	pip->cmds[index] = pip->script;
}
