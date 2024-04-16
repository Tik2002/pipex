/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/16 02:17:58 by senate            #+#    #+#             */
/*   Updated: 2024/04/16 04:21:11 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*get_path(char **env)
{
	int		i;
	char	*path;

	i = -1;
	while(env[++i])
	{
		path = ft_strnstr(env[i], "PATH=/", ft_strlen(env[i]));
		if(path)
		{
			while(*path != '/')
				path++;
			return (ft_strdup(path));
		}
	}
	return (0);
}

char	**get_env(char *path)
{
	char	**newEnv;
	ft_printf("PATH=%s\n", path);
	newEnv = ft_split(path, ':');
	free(path);
	return (newEnv);
}
