/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tigpetro <tigpetro@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/09 19:33:17 by tigpetro          #+#    #+#             */
/*   Updated: 2024/04/23 19:04:08 by tigpetro         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <pipex.h>

char	*gnl_strchr(char *s, int c)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return (s + i);
		i++;
	}
	return (0);
}

void	gnl_strjoin(char **line, char *buff)
{
	char	*tmp;
	int		i;
	int		j;
	int		k;

	i = 0;
	j = 0;
	while (buff[j])
		j++;
	while ((*line)[i])
		i++;
	tmp = (char *)malloc(i + j + 1);
	if (!tmp)
		return ;
	i = 0;
	j = 0;
	k = 0;
	while ((*line)[i])
		tmp[k++] = (*line)[i++];
	while (buff[j])
		tmp[k++] = buff[j++];
	tmp[k] = '\0';
	free (*line);
	(*line) = tmp;
}

void	gnl_new_line(char **line, char *next_lines)
{
	char	*tmp;
	int		i;

	i = 0;
	while (next_lines[i])
		i++;
	tmp = (char *)malloc(i + 1);
	if (!tmp)
		return ;
	tmp[i--] = '\0';
	while (i >= 0)
	{
		tmp[i] = next_lines[i];
		i--;
	}
	free (*line);
	(*line) = tmp;
}

char	*gnl_strdup(char **line)
{
	int		i;
	char	*res;

	i = 0;
	if (!(**line))
	{
		free (*line);
		*line = 0;
		return (0);
	}
	while ((*line)[i])
		if ((*line)[i++] == '\n')
			break ;
	res = (char *)malloc(i + 1);
	if (!res)
		return (0);
	res[i--] = '\0';
	while (i >= 0)
	{
		res[i] = (*line)[i];
		i--;
	}
	return (res);
}

void	gnl_read(int fd, char **line)
{
	char	*buff;
	ssize_t	byte;

	buff = (char *)malloc(BUFFER_SIZE + 1);
	buff[BUFFER_SIZE] = '\0';
	while (!gnl_strchr(*line, '\n'))
	{
		byte = read(fd, buff, BUFFER_SIZE);
		buff[byte] = '\0';
		if (!byte)
			break ;
		gnl_strjoin(line, buff);
	}
	free (buff);
}
