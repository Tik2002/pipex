/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:40 by senate            #+#    #+#             */
/*   Updated: 2024/04/23 03:13:46 by senate           ###   ########.fr       */
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

typedef struct s_pipex
{
	char	***cmds;
	int		cmds_count;
	int		*fd;
	int		fd_index;
	int		cmds_index;
	int		is_doc;
	char	**new_env;
}	t_pipex;

// pipex
void	pipex(char **env, char **av, t_pipex *pip, int ac);

// utils
void	destroy(t_pipex *pip);
int		get_env(t_pipex *pip, char *path);
char	*get_path(char **env);

// checks
int		check_pipex(t_pipex *pip, char **av, char **env);
int		get_commands(char **av, t_pipex *pip);

#endif //PIPEX_H
