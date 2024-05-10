/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:40 by senate            #+#    #+#             */
/*   Updated: 2024/04/25 20:59:43 by tigpetro         ###   ########.fr       */
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

# define BUFFER_SIZE 1024

typedef struct s_pipex
{
	char	***cmds;
	char	**script;
	int		cmds_count;
	int		cmds_err_count;
	int		*fd;
	int		fd_index;
	int		cmds_index;
	int		doc_flag;
	char	**new_env;
	char	*limiter;
}	t_pipex;

// GNEL
char	*get_next_line(int fd);
char	*gnl_strchr(char *s, int c);
void	gnl_strjoin(char **line, char *buff);
void	gnl_new_line(char **line, char *next_lines);
char	*gnl_strdup(char **line);
void	gnl_read(int fd, char **line);

// pipex
void	pipex(char **env, char **av, t_pipex *pip);

// utils
void	close_pipes(t_pipex *pip);
void	destroy(t_pipex *pip);
int		get_env(t_pipex *pip, char *path);
char	*get_path(char **env);

// process
void	start_proc(t_pipex *pip, char **av, char **env, int i);

// checks
void	check_here_doc(char **av, t_pipex *pip);
int		check_pipex(t_pipex *pip, char **av, char **env);

// script
void	malloc_script(t_pipex *pip, int index);

// more utils
int		get_commands(char **av, t_pipex *pip);

#endif //PIPEX_H
