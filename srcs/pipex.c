/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/04/12 02:46:21 by senate            #+#    #+#             */
/*   Updated: 2024/05/10 16:41:22 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

void	pipex(char **env, char **av, t_pipex *pip)
{
	pid_t	pid;
	int		i;

	i = 0;
	while ((i < pip->cmds_count))
	{
		pid = fork();
		if (pid < 0)
		{
			perror("pipex 3");
			exit(1);
		}
		if (!pid)
			start_proc(pip, av, env, i);
		else if (!i && pip->doc_flag)
			wait(NULL);
		pip->fd_index += 2;
		pip->cmds_index++;
		++i;
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
	pipex(env, av, &pip);
	close_pipes(&pip);
	while (wait(NULL) != -1)
		(void)ac;
	destroy(&pip);
	return (0);
}
