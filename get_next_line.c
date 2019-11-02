/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/11/02 01:31:22 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

int get_next_line(int fd, char **line)
{
	static char tmp[BUFFER_SIZE];
	char buff[BUFFER_SIZE];

	
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
