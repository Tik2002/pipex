/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/04/22 20:18:24 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_left_proc(t_pipex *pip, char **env, char *file_name)
{
	int infile;

	infile = open(file_name, O_RDONLY);
	if (infile < 0)
	{
		perror("pipex");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pip->fd[pip->fd_index + 1], STDOUT_FILENO);
	close(infile);
	close(pip->fd[pip->fd_index++]);
	close(pip->fd[pip->fd_index++]);
	execve(pip->cmds[0][0], pip->cmds[0], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);

}

static void	_mid_proc(t_pipex *pip, char **env)
{
	dup2(pip->fd[pip->fd_index], STDIN_FILENO);
	dup2(pip->fd[pip->fd_index + 1], STDOUT_FILENO);
	close(pip->fd[pip->fd_index++]);
	close(pip->fd[pip->fd_index++]);
	execve(pip->cmds[0][0], pip->cmds[0], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

static void	_right_proc(t_pipex *pip, char **env, char *file_name)
{
	int outfile;

	outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("pipex");
		exit(1);
	}
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(fd[0]);
	close(fd[1]);
	execve(pip.right[0], pip.right, env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

int	pipex(char **env, char **av, t_pipex *pip)
{
	pid_t	pid1;
	pid_t	pid2;

	pid1 = fork();
	if (pid1 < 0)
	{
		perror("pipex");
		exit(1);
	}
	if (!pid1)
		_left_proc(pip, env, av[1]);
	pid2 = fork();
	if (pid2 < 0)
	{
		perror("pipex");
		exit(1);
	}
	if (!pid2)
		_right_proc(fd, pip, env, av[4]);
	close(fd[0]);
	close(fd[1]);
	waitpid(pid1, NULL, 0);
	waitpid(pid2, NULL, 0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pip;

	if (ac < 5)
	{
		perror("pipex");
		exit(1);
	}
	pip.cmds_count = ac - 3;
	if (check_pipex(&pip, av, env))
	{
		destroy(&pip);
		perror("pipex");
		exit(1);
	}
	pip.fd_index = 0;
	pip.cmds_index = 0;
	return (pipex(env, av, &pip));
}
