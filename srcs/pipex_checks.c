/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:32:54 by senate            #+#    #+#             */
/*   Updated: 2024/04/22 20:01:36 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*_cmd_with_path(char *cmd, char **new_env)
{
	char	*res;
	char	*new_path;
	int		i;

	i = -1;
	while (new_env[++i])
	{
		new_path = ft_strjoin(new_env[i], "/");
		res = ft_strjoin(new_path, cmd);
		free(new_path);
		if (!access(res, F_OK | X_OK))
			return (res);
		free(res);
	}
	return (ft_strdup("/bin/bash"));
}

int	get_commands(char **av, t_pipex *pip)
{
	int		i;
	char	*cmd;

	i = 0;
	pip->cmds = (char ***)malloc(sizeof(char **) * pip->cmds_count);
	while (i < pip->cmds_count)
	{
		pip->cmds[i] = ft_split(av[i + 2], ' ');
		cmd = _cmd_with_path(pip->cmds[i][0], pip->new_env);
		free(pip->cmds[i][0]);
		pip->cmds[i][0] = ft_strdup(cmd);
		if (!pip->cmds[i][0])
			return (1);
		free(cmd);
		i++;
	}
	return (0);
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
		if(pipe(pip->fd + i) == -1)
			return (1);
		i += 2;
	}
	return (0);
}

int	check_pipex(t_pipex *pip, char **av, char **env)
{
	pip->new_env = 0;
	pip->cmds = 0;
	pip->fd = 0;
	if (get_env(pip, get_path(env)) || get_commands(av, pip) || check_fd(pip))
		return (1);
	return (0);
}
