/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:21:44 by tamather          #+#    #+#             */
/*   Updated: 2019/11/06 08:39:35 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strchr(const char *s, int c)
{
	if (!s)
		return (0);
	while (*s)
	{
		if (*s == c)
			return ((char*)s);
		s++;
	}
	if (c == '\0')
		return ((char*)s);
	return (0);
}

size_t	ft_strlen(const char *str)
{
	int n;

	n = 0;
	while (*str != '\0')
	{
		n++;
		str++;
	}
	return (n);
}

size_t	ft_strlcpy(char *dst, const char *src, size_t size)
{
	size_t i;

	i = 0;
	while (src[i])
	{
		if (size && i < size - 1)
			*dst++ = src[i];
		i++;
	}
	if (size)
		*dst = '\0';
	return (i);
}

char	*ft_strjoin(char *s1, char const *s2)
{
	char *out;

	if (!s1 || !s2)
		return (0);
	if (!(out = malloc(sizeof(char) * (ft_strlen((char*)s1)
		+ ft_strlen((char*)s2) + 1))))
		return (0);
	ft_strlcpy(out, s1, ft_strlen(s1) + 1);
	ft_strlcpy(out + ft_strlen(s1), s2, ft_strlen(s2) + 1);
	free(s1);
	return (out);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	int		i;
	char	*out;

	i = 0;
	if (!s)
		return (0);
	if (!(out = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (start <= ft_strlen((char*)s))
	{
		while (s[i + start] && i < (int)len)
		{
			out[i] = s[i + start];
			i++;
		}
	}
	out[i] = '\0';
	return (out);
}
