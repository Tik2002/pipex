/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:17:58 by senate            #+#    #+#             */
/*   Updated: 2024/04/23 03:08:29 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	destroy(t_pipex *pip)
{
	while (*(pip->new_env))
	{
		free(*(pip->new_env));
		pip->new_env++;
	}
	// while (*(pip->cmds))
	// {
	// 	while (**(pip->cmds))
	// 	{
	// 		free(**(pip->cmds));
	// 		(*(pip->cmds))++;
	// 	}
	// 	free(*(pip->cmds));
	// 	pip->cmds++;
	// }
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
		path = ft_strnstr(env[i], "PATH=/", ft_strlen(env[i]));
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
