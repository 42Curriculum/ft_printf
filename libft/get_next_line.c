/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jjosephi <jjosephi@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/09/23 16:49:46 by jjosephi          #+#    #+#             */
/*   Updated: 2019/12/05 22:14:25 by jjosephi         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "get_next_line.h"
#include <stdio.h>

static int		check_line(char *str)
{
	int i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == '\n')
			return (TRUE);
		i++;
	}
	return (FALSE);
}

static char		*cpy_nn(char **line, char **next_line)
{
	int		i;
	char	*temp;

	i = 0;
	temp = *next_line;
	while ((*next_line)[i] != '\n' && (*next_line)[i] != '\0')
		i++;
	*line = ft_strnew(i);
	*line = ft_strncpy(*line, *next_line, i);
	*next_line = ft_strdup(*next_line + (i + 1));
	ft_bzero(temp, ft_strlen(temp));
	free(temp);
	return (*line);
}

static int		norm_hates_me(char **next_line, int fd, char **line)
{
	if ((check_line(next_line[fd])))
	{
		if (next_line[fd][0] == '\0')
			return (0);
		*line = cpy_nn(line, &next_line[fd]);
		return (1);
	}
	if (ft_strlen(next_line[fd]) > 0)
	{
		*line = ft_strdup(next_line[fd]);
		ft_strdel(&next_line[fd]);
		next_line[fd] = NULL;
		return (1);
	}
	return (0);
}

static int		error_check(int fd, char **line, char *buffer, char **next_line)
{
	if (fd < 0 || !line || read(fd, buffer, 0) < 0)
		return (FALSE);
	if (!(next_line[fd]))
		next_line[fd] = ft_strnew(0);
	return (TRUE);
}

int				get_next_line(const int fd, char **line)
{
	char		buffer[BUFF_SIZE + 1];
	static char *next_line[FD_NOTMAX];
	int			b;
	char		*temp;

	if (error_check(fd, line, buffer, next_line) == FALSE)
		return (-1);
	while ((b = read(fd, buffer, BUFF_SIZE)))
	{
		buffer[b] = '\0';
		temp = next_line[fd];
		next_line[fd] = ft_strjoin(next_line[fd], buffer);
		free(temp);
		if ((check_line(next_line[fd])))
		{
			*line = cpy_nn(line, &next_line[fd]);
			ft_bzero(buffer, BUFF_SIZE);
			return (1);
		}
	}
	if (norm_hates_me(next_line, fd, line) == TRUE)
		return (1);
	else
		return (0);
}
