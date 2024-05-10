/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_more_utils.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:49:58 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/25 20:58:36 by tigpetro         ###   ########.fr       */
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
	return (0);
}

static int	_get_commands_util(t_pipex *pip, int i)
{
	char	*cmd;

	if (ft_strchr(pip->cmds[i][0], '/') &&
		!access(pip->cmds[i][0], X_OK | F_OK))
	{
		malloc_script(pip, i);
		return (0);
	}
	cmd = _cmd_with_path(pip->cmds[i][0], pip->new_env);
	if (!cmd)
		return (1);
	free(pip->cmds[i][0]);
	pip->cmds[i][0] = ft_strdup(cmd);
	if (!pip->cmds[i][0])
		return (1);
	free(cmd);
	return (0);
}

int	get_commands(char **av, t_pipex *pip)
{
	int		i;
	int		j;
	int		res;

	i = 0;
	res = 0;
	pip->cmds = (char ***)malloc(sizeof(char **) * ((pip->cmds_count) + 1));
	if (!pip->cmds)
		return (1);
	while (i < pip->cmds_count)
	{
		j = i + 2 + pip->doc_flag;
		pip->cmds[i] = ft_split(av[j], ' ');
		res = _get_commands_util(pip, i);
		if (res)
			break ;
		pip->cmds_err_count++;
		i++;
	}
	pip->cmds[pip->cmds_count] = 0;
	return (res);
}
