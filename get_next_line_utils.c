/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tamather <tamather@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/10/26 23:21:44 by tamather          #+#    #+#             */
/*   Updated: 2019/10/27 20:21:19 by tamather         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

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

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t i;
	size_t j;

	i = -1;
	while (++i < size && *dest)
		dest++;
	if (i == size)
		return (i + ft_strlen((char*)src));
	j = -1;
	while (src[++j])
		if (j < size - i - 1)
			*dest++ = src[j];
	*dest = '\0';
	return (i + j);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char *out;

	if (!(out = malloc(sizeof(char) * (ft_strlen((char*)s1)
		+ ft_strlen((char*)s2) + 1))))
		return (0);
	ft_strlcpy(out, s1, ft_strlen((char*)s1) + 1);
	ft_strlcat(out, s2, ft_strlen((char*)s1) + ft_strlen((char*)s2) + 1);
	return (out);
}
