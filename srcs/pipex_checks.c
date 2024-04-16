/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_checks.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:32:54 by senate            #+#    #+#             */
/*   Updated: 2024/04/16 04:20:52 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static char	*_cmdWithPath(char *cmd, char **newEnv)
{
	char	*res;
	char	*newPath;
	int		i;

	i = -1;
	res = 0;
	while (newEnv[++i])
	{
		free(res);
		newPath = ft_strjoin(newEnv[i], "/");
		res = ft_strjoin(newPath, cmd);
		free(newPath);
		if (!access(res, F_OK))
			return (res);
	}
	return (0);
}

t_cmds	get_commands(char **av, char **newEnv)
{
	t_cmds	cmds;
	char	*cmd1;
	char	*cmd2;

	cmds.left = ft_split(av[2], ' ');
	cmds.right = ft_split(av[3], ' ');
	cmd1 = _cmdWithPath(cmds.left[0], newEnv);
	cmd2 = _cmdWithPath(cmds.right[0], newEnv);
	if (!cmd1 || !cmd2)
	{
		perror("Wrong command input\n");
		exit(1);
	}
	free(cmds.left[0]);
	free(cmds.right[0]);
	cmds.left[0] = cmd1;
	cmds.right[0] = cmd2;
	return (cmds);
}
