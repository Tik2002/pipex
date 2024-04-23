/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/04/23 22:27:22 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

static void	_start_proc(t_pipex *pip, char **env, char *file_name)
{
	int		infile;
	char	*line;

	infile = 0;
	if (pip->doc_flag)
	{
		line = get_next_line(0);
		while(ft_strncmp(line, pip->limiter, ft_strlen(pip->limiter)))
		{
			// ft_putstr_fd(line, infile);
			free(line);
			line = get_next_line(0);
		}
		free (line);
	}
	else
	{
		infile = open(file_name, O_RDONLY);
		if (infile < 0)
		{
			perror("pipex 1");
			exit(1);
		}
		dup2(infile, STDIN_FILENO);
		close(infile);
	}
	dup2(pip->fd[1], STDOUT_FILENO);
	close_pipes(pip);
	ft_printf("%s\n", "JUJIK");
	ft_printf("%s\n%s\n", pip->cmds[pip->cmds_index][0]);
	ft_printf("%s\n", "JUJIKISHE");
	execve(pip->cmds[pip->cmds_index][0], pip->cmds[pip->cmds_index], env);
	ft_putstr_fd("command not found\n", 2);
	// destroy(pip);
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
	int		outfile;

	outfile = open(file_name, O_WRONLY | O_CREAT | O_TRUNC * !(pip->doc_flag) | O_APPEND * pip->doc_flag, 0644);
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
				_start_proc(pip, env, av[1]);
			else if (i == pip->cmds_count - 1)
				_end_proc(pip, env, av[ac - 1]);
			else
				_mid_proc(pip, env);
		}
		else if(!i && pip->doc_flag)
			wait(NULL);
		pip->fd_index += 2;
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
	check_here_doc(av, &pip);
	pip.cmds_count = ac - 3 - pip.doc_flag;
	if (check_pipex(&pip, av, env))
	{
		destroy(&pip);
		perror("pipex 5");
		exit(1);
	}
	pip.fd_index = 0;
	pip.cmds_index = pip.doc_flag;
	pipex(env, av, &pip, ac);
	close_pipes(&pip);
	while (wait(NULL) != -1)
		(void)ac;
	destroy(&pip);
	return (0);
}

// int	main(int ac, char **av, char **env)
// {
// 	a_main(ac, av, env);
// 	return (0);
// }
