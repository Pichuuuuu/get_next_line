/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/10/28 06:04:18 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *is_end_line(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if(s[i] == '\n')
			return(s + i);
		i++;
	}
	return (0);
}


int get_next_line(int fd, char **line)
{
	int size;
	static char *tmp = 0;
	char *out;
	char *buff;

	out = "";
	if((*line = malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	size = read(fd, buff, BUFFER_SIZE);
	printf("%s", buff);
	*line = ft_strjoin(out, buff);
	
	
	return(0);
}

int main(int argc, char const *argv[])
{
	char *line;
	
	int fd = open("test", O_RDONLY);
	get_next_line(fd, &line);
	printf("%s", line);
	return 0;
}
