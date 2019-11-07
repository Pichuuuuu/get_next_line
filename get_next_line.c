/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/11/07 12:57:01 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char	*mk_line(char *buff, char *line, char **tmp)
{
	int		i;
	char	*out;

	i = 0;
	if (*tmp)
	{
		out = ft_substr(*tmp, 0, ft_strlen(*tmp));
		free(*tmp);
		*tmp = 0;
	}
	else if (buff[0])
		out = ft_strjoin(line, buff);
	else
	{
		free(line);
		out = ft_substr("", 0, 1);
	}
	return (out);
}

char	*a_endl(char *s, char **tmp)
{
	int		i;
	char	*out;

	i = 0;
	while (s[i] != '\n')
		i++;
	*tmp = ft_substr(s, i + 1, ft_strlen(s));
	if (!(**tmp))
	{
		free(*tmp);
		*tmp = 0;
	}
	out = ft_substr(s, 0, i);
	free(s);
	return (out);
}

int		get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		buff[BUFFER_SIZE + 1];
	int			size;

	*line = 0;
	buff[0] = 0;
	size = (fd != -1) ? 1 : -1;
	while (size > 0)
	{
		*line = mk_line(buff, *line, &tmp);
		if ((ft_strchr(*line, '\n')))
		{
			*line = a_endl(*line, &tmp);
			return (((*line) ? 1 : -1));
		}
		size = read(fd, buff, BUFFER_SIZE);
		buff[size] = '\0';
	}
	free(tmp);
	return ((!size) ? 0 : -1);
}

int main(int argc, char const *argv[])
{
	int fd;
	char *line;
	int i;
	
	fd = open(argv[1], O_RDONLY);
	while((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d ==> %s\n", i, line);
		free(line);
	}
	printf("%d ==> %s\n", i, line);
	free(line);
	while(1)
		;
	return 0;
}
