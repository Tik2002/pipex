/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: senate <senate@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/04/16 04:26:32 by senate           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_child_proc(int	*fd, t_cmds cmds, char **newEnv, int infile)
{
	wait(NULL);
	dup2(infile, STDIN_FILENO);
	dup2(fd[1], STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmds.left[0], cmds.left, newEnv);
}

static void _parent_proc(int	*fd, t_cmds cmds, char **newEnv, int outfile)
{
	dup2(fd[0], STDIN_FILENO);
	dup2(outfile, STDOUT_FILENO);
	close(fd[0]);
	close(fd[1]);
	execve(cmds.right[0], cmds.right, newEnv);
}

int	pipex(char **av, char **newEnv, t_cmds cmds)
{
	int	fd[2];
	int	pid;
	int	infile;
	int	outfile;

	infile = open(av[1], O_WRONLY);
	outfile = open(av[4], O_RDWR | O_CREAT | O_TRUNC, 0777);
	if (pipe(fd) == -1)
		return (2);
	pid = fork();
	if (pid < 0)
		return (3);
	if (!pid)
		_child_proc(fd, cmds, newEnv, infile);
	else
		_parent_proc(fd, cmds, newEnv, outfile);
	waitpid(pid, 0, 0);
	return (0);
}

int	main(int ac, char **av, char **env)
{
	char	**newEnv;
	t_cmds	cmds;

	if (ac != 5)
	{
		perror("Program must take 4 arguments\n");
		exit(1);
	}
	else if (!av[2] || !av[3])
	{
		perror("Empty command input\n");
		exit(1);
	}
	newEnv = get_env(get_path(env));
	cmds = get_commands(av, newEnv);
	pipex(av, newEnv, cmds);
	return (0);
}
