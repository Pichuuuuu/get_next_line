/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:20:38 by tamather          #+#    #+#             */
/*   Updated: 2019/11/19 06:40:54 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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
