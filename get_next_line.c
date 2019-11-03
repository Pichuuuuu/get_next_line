/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/11/03 06:06:51 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *a_endl(char *s)
{
	int i;
	char *out;

	i = 0;
	while (s[i] != '\n')
		i++;
	if(!(out = malloc(sizeof(char) * (i + 1))))
		return(0);
	ft_strlcpy(out, s, i + 1);
	return(out);
}

int get_next_line(int fd, char **line)
{
	static char *tmp;
	char buff[BUFFER_SIZE + 1];
	size_t size;

	while(!(size = read(fd, buff, BUFFER_SIZE)))
	{
		if(size == -1)
			return(-1);
		if(!ft_strchr(buff, '\n'))
			line;
		if((tmp = ft_strchr(buff, '\n')))
		{
			*line = a_endl(buff);
			return(((line) ? 1 : -1));
		}

	}
	return 0;
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
