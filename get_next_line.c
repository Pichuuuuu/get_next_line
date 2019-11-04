/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/11/04 08:06:43 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *mk_line(char *buff, char *line,char **tmp)
{
	int i;
	char *out;
	i = 0;
	if (*tmp)
	{
		while((*tmp)[i] != '\n' && (*tmp)[i])
			i++;
		if((*tmp)[i] == '\0')
			tmp = 0;
		out = ft_substr(*tmp, 0, i);
		*tmp = ft_substr(*tmp, i, ft_strlen(*tmp));
		printf("--%s--\n", *tmp);
	}
	else if(line)
	{
		out = ft_strjoin(line, buff);
	}
	else
	{
		out = ft_substr("", 0, 1);
	}
	return (out);
}

char *a_endl(char *s, char **tmp)
{
	int i;
	char *out;

	i = 0;
	while(s[i] != '\n')
		i++;
	*tmp = ft_substr(s, i + 1, ft_strlen(s));
	out = ft_substr(s, 0, i);
	return (out);
}

int get_next_line(int fd, char **line)
{
	static char *tmp;
	char buff[BUFFER_SIZE + 1];
	int size;
	*line = 0;
	
	size = 1;
	while (size > 0)
	{
		*line = mk_line(buff, *line, &tmp);
		printf("--%s--\n", tmp);
		if((ft_strchr(*line, '\n')))
		{
			*line = a_endl(*line, &tmp);
			return (((*line) ? 1 : -1));
		}
		size = read(fd, buff, BUFFER_SIZE);
	}
	return ((!size) ? 0 : -1);
}

int main(int argc, char const *argv[])
{
	char *line;
	int i;

	int fd = open("test", O_RDONLY);
	while ((i = get_next_line(fd, &line)) > 0)
	{
		printf("%d => %s\n", i, line);
		free(line);
	}
	printf("%d => %s\n", i, line);
	free(line);
	while(1);
	return (0);
}
