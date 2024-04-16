/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:40 by senate            #+#    #+#             */
/*   Updated: 2024/04/16 04:19:47 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include <libft.h>
# include <ft_printf.h>
# include <errno.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/wait.h>

typedef struct s_cmds
{
	char	**left;
	char	**right;
}	t_cmds;


// pipex
int		pipex(char **av, char **env, t_cmds cmds);

// utils
char	**get_env(char *path);
char	*get_path(char **env);

// checks
t_cmds	get_commands(char **av, char **newEnv);

#endif //PIPEX_H
