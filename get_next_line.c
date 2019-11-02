/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/10/30 21:25:01 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int end_line(char **buff, char **line)
{
	int i;

	i = 0;
	while(*buff[i] != '\n' && *buff[i])
		i++;
	*buff[i] = '\0';
	*line = ft_strjoin("", *buff);
	free(*buff);
	return(1);
}

int read_to_endline(int fd, char **line)
{
	char buff[BUFFER_SIZE];
	char *out;
	int size;

	size = 1;
	line = 0;
	while(size > 0)
	{
		if((size = read(fd, buff, BUFFER_SIZE) == -1))
			return(-1);
		if(ft_strchr(buff, '\n'))
			return(end_line(&buff, &*line));
		else if(!ft_strchr(buff, '\n'))
		{
			out = ft_strjoin(*line, buff);
			if(**line)
				free(line);
			*line = out;
		}
	}
	return(0);
}

int get_next_line(int fd, char **line)
{
	static char tmp[BUFFER_SIZE];
	char buff[BUFFER_SIZE];
	int size;
	
	if(!(line = malloc(1)))
		return(-1);
	return(0);
}

int main(int argc, char const *argv[])
{
	char *line;
	int i;

	int fd = open("test", O_RDONLY);
	while((i = get_next_line(fd, &line)))
	{
		printf("%d %s\n", i, line);
		free(line);
	}
	printf("%d %s\n", i, line);
	free(line);
	return (0);
}
