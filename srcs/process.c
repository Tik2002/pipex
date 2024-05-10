/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/25 20:44:02 by tigpetro          #+#    #+#             */
/*   Updated: 2024/05/10 16:41:43 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_here_doc_start_proc(t_pipex *pip, char *here_doc)
{
	char	*line;
	int		infile;

	infile = open(here_doc, O_RDWR | O_CREAT | O_TRUNC, 0644);
	if (infile < 0)
	{
		perror("pipex 1");
		exit(1);
	}
	line = get_next_line(STDIN_FILENO);
	while ((line[0] == '\n' && pip->limiter)
		|| ft_strncmp(line, pip->limiter, ft_strlen(line) - 1))
	{
		ft_putstr_fd(line, infile);
		free(line);
		line = get_next_line(STDIN_FILENO);
	}
	free(line);
	close(infile);
}

static void	_start_proc(t_pipex *pip, char **env, char *file_name)
{
	int		infile;

	if (pip->doc_flag)
		_here_doc_start_proc(pip, file_name);
	infile = open(file_name, O_RDONLY);
	if (infile < 0)
	{
		perror("pipex 1");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	close(infile);
	dup2(pip->fd[1], STDOUT_FILENO);
	close_pipes(pip);
	if (pip->doc_flag)
		unlink(file_name);
	execve(pip->cmds[pip->cmds_index][0], pip->cmds[pip->cmds_index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

static void	_mid_proc(t_pipex *pip, char **env)
{
	dup2(pip->fd[pip->fd_index - 2], STDIN_FILENO);
	dup2(pip->fd[pip->fd_index + 1], STDOUT_FILENO);
	close_pipes(pip);
	execve(pip->cmds[pip->cmds_index][0], pip->cmds[pip->cmds_index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

static void	_end_proc(t_pipex *pip, char **env, char *file_name)
{
	int	outfile;

	outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC
			* !(pip->doc_flag) | O_APPEND * pip->doc_flag, 0644);
	if (outfile < 0)
	{
		perror("pipex 2");
		exit(1);
	}
	dup2(pip->fd[pip->fd_index - 2], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close_pipes(pip);
	execve(pip->cmds[pip->cmds_index][0], pip->cmds[pip->cmds_index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

void	start_proc(t_pipex *pip, char **av, char **env, int i)
{
	if (!i)
		_start_proc(pip, env, av[1]);
	else if (i == pip->cmds_count - 1)
		_end_proc(pip, env, av[pip->cmds_count + pip->doc_flag + 2]);
	else
		_mid_proc(pip, env);
}
