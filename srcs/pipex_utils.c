/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:17:58 by senate            #+#    #+#             */
/*   Updated: 2024/04/25 20:51:29 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	close_pipes(t_pipex *pip)
{
	int	i;

	i = 0;
	while (i < (pip->cmds_count - 1) * 2)
		close(pip->fd[i++]);
}

void	destroy(t_pipex *pip)
{
	int	i;
	int	j;

	i = 0;
	while (pip->new_env[i])
		free(pip->new_env[i++]);
	i = 0;
	while ((i < pip->cmds_err_count) && pip->cmds[i])
	{
		j = 0;
		while (pip->cmds[i][j])
			free(pip->cmds[i][j++]);
		free(pip->cmds[i++]);
	}
	free(pip->cmds);
	free(pip->new_env);
	free(pip->fd);
	free(pip->limiter);
}

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = -1;
	while (env[++i])
	{
		path = ft_strnstr(env[i], "PATH=", ft_strlen(env[i]));
		if (path)
		{
			while (*path != '/')
				path++;
			return (ft_strdup(path));
		}
	}
	return (0);
}

int	get_env(t_pipex *pip, char *path)
{
	pip->new_env = ft_split(path, ':');
	free(path);
	if (!pip->new_env)
		return (1);
	return (0);
}
