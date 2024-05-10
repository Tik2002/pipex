/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:32:54 by senate            #+#    #+#             */
/*   Updated: 2024/04/25 20:50:23 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	check_here_doc(char **av, t_pipex *pip)
{
	pip->doc_flag = 0;
	pip->limiter = NULL;
	if (!ft_strncmp(av[1], "here_doc", ft_strlen(av[1])))
	{
		pip->doc_flag = 1;
		pip->limiter = ft_strdup(av[2]);
	}
}

static int	check_fd(t_pipex *pip)
{
	int	i;
	int	limit;

	i = 0;
	limit = (pip->cmds_count - 1) * 2;
	pip->fd = (int *)malloc(limit * sizeof(int));
	while (i < limit)
	{
		if (pipe(pip->fd + i) == -1)
			return (1);
		i += 2;
	}
	return (0);
}

int	check_pipex(t_pipex *pip, char **av, char **env)
{
	pip->new_env = 0;
	pip->cmds = 0;
	pip->cmds_err_count = 1;
	pip->fd = 0;
	pip->fd_index = 0;
	pip->cmds_index = 0;
	if (get_env(pip, get_path(env)) || get_commands(av, pip) || check_fd(pip))
		return (1);
	return (0);
}
