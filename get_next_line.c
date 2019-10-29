/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/10/29 05:55:39 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <stdio.h>

char *endline(char *buff)
{
	int i;
	char *cpy;
	
	i = 0;
	cpy = buff;
	while(cpy[i] != '\n' && cpy[i])
		i++;
	cpy[i] = '\0';
	return(buff);
}

char *check_tmp(char *tmp)
{
	int i;
	char *out;

	i = 0;
	if(ft_strchr(tmp, '\n'))
	{
		out = ft_strjoin("", ft_strchr(tmp, '\n'));
		free(tmp);
		return (out);
	}
	else if (tmp)
	{
		out = ft_strjoin("", tmp);
		return (out);
	}
	else
		return ("");
	
}

int get_next_line(int fd, char **line)
{
	int size;
	static char *tmp = "";
	char *out;
	char *buff;

	if (!(buff = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (0);
	tmp = check_tmp(tmp);
	if((size = read(fd, buff, BUFFER_SIZE)) < 0)
		return(size);
	while(size > 0)
	{
		if(ft_strchr(buff, '\n') || !buff[0])
		{
			out = ft_strjoin(tmp, endline(buff));
			tmp = buff;
			*line = out;
			return(1);
		}
		else
		{
			out = ft_strjoin(tmp, buff);
			tmp = out;
			if((size = read(fd, buff, BUFFER_SIZE)) < 0)
				return(size);
		}
	}
	free(buff);
	*line = tmp;
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
	}
	printf("%d %s\n", i, line);
	free(line);
	return (0);
}
