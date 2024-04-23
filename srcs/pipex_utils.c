/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:17:58 by senate            #+#    #+#             */
/*   Updated: 2024/04/23 21:35:06 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	close_pipes(t_pipex *pip)
{
	int	i;

	i = 0;
	while(i < (pip->cmds_count - 1) * 2)
		close(pip->fd[i++]);
}

void	malloc_script(t_pipex *pip, char *av, int index)
{
	pip->cmds[index] = (char **)malloc(sizeof(char *) * 3);
	if (!pip->cmds[index])
	{
		perror("pipex");
		exit(1);
	}
	pip->cmds[index][0] = ft_strdup("/bin/bash");
	pip->cmds[index][1] = ft_strdup(av);
	pip->cmds[index][2] = 0;
}

void	destroy(t_pipex *pip)
{
	int	i;
	int	j;

	i = 0;
	while (pip->new_env[i])
		free(pip->new_env[i++]);
	i = 0;
	while (i < pip->cmds_count)
	{
		j = 0;
		while (pip->cmds[i][j])
			free(pip->cmds[i][j++]);
		free(pip->cmds[i++]);
	}
	free(pip->cmds);
	free(pip->new_env);
	free(pip->fd);
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
