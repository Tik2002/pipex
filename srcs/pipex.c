/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/04/23 03:20:10 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_start_proc(t_pipex *pip, char **env, char *file_name, int index)
{
	int infile;

	infile = open(file_name, O_RDONLY);
	if (infile < 0)
	{
		perror("pipex 1");
		exit(1);
	}
	dup2(infile, STDIN_FILENO);
	dup2(pip->fd[pip->fd_index + 1], STDOUT_FILENO);
	close(infile);
	close(pip->fd[pip->fd_index++]);
	close(pip->fd[pip->fd_index++]);
	execve(pip->cmds[index][0], pip->cmds[index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

static void	_mid_proc(t_pipex *pip, char **env, int index)
{
	dup2(pip->fd[pip->fd_index], STDIN_FILENO);
	dup2(pip->fd[pip->fd_index + 1], STDOUT_FILENO);
	close(pip->fd[pip->fd_index++]);
	close(pip->fd[pip->fd_index++]);
	execve(pip->cmds[index][0], pip->cmds[index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

static void	_end_proc(t_pipex *pip, char **env, char *file_name, int index)
{
	int outfile;

	outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC, 0644);
	if (outfile < 0)
	{
		perror("pipex 2");
		exit(1);
	}
	dup2(pip->fd[pip->fd_index], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(outfile);
	close(pip->fd[pip->fd_index++]);
	close(pip->fd[pip->fd_index]);
	execve(pip->cmds[index][0], pip->cmds[index], env);
	ft_putstr_fd("command not found\n", 2);
	destroy(pip);
}

void	pipex(char **env, char **av, t_pipex *pip, int ac)
{
	pid_t	pid;
	int		i;

	i = -1;
	while (++i < pip->cmds_count)
	{
		pid = fork();
		if (pid < 0)
		{
			perror("pipex 3");
			exit(1);
		}
		if (!pid)
		{
			if (!i)
				_start_proc(pip, env, av[1], pip->cmds_index);
			else if (i == pip->cmds_count - 1)
				_end_proc(pip, env, av[ac - 1], pip->cmds_index);
			else
				_mid_proc(pip, env, pip->cmds_index);
		}
		// close(pip->fd[pip->fd_index - 2]);
		// close(pip->fd[pip->fd_index - 1]);
		pip->cmds_index++;
	}
}

int	main(int ac, char **av, char **env)
{
	t_pipex	pip;

	if (ac < 5)
	{
		perror("pipex 4");
		exit(1);
	}
	pip.cmds_count = ac - 3;
	if (check_pipex(&pip, av, env))
	{
		destroy(&pip);
		perror("pipex 5");
		system("leaks pipex");
		exit(1);
	}
	pip.fd_index = 0;
	pip.cmds_index = 0;
	// while(pip.fd[pip.fd_index])
	pipex(env, av, &pip, ac);
	while (wait(NULL) != -1)
		(void)ac;
	destroy(&pip);
	system("leaks pipex");
	return (0);
}
