/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/10/27 07:19:38 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	int size;
	static char *tmp = 0;
	if(!(*line = (char*)malloc(sizeof(char) * BUFFER_SIZE + 1)))
		return (0);
	size = read(fd, *line, BUFFER_SIZE);
	
}

int main(int argc, char const *argv[])
{
	char *line = 0;
	int fd = open("test", O_RDONLY);
	printf("%d", get_next_line(fd, &line));
	return 0;
}
