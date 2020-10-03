/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: trcottam <trcottam@student.s19.be>         +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/10/01 18:35:09 by trcottam          #+#    #+#             */
/*   Updated: 2020/10/01 19:03:46 by trcottam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*ft_strcpy(char *dst, const char *src)
{
	size_t	i;

	i = 0;
	while (src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (dst);
}

int		ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_strchr(const char *s, int c)
{
	int	i;

	if (!c)
		return ((char *)s + ft_strlen(s));
	i = 0;
	while (s[i])
	{
		if (s[i] == c)
			return ((char *)s + i);
		i++;
	}
	return (NULL);
}

int		str_append(char **line, const char *buffer)
{
	char	*old_line;
	int		new_line_len;

	old_line = *line;
	new_line_len = ft_strlen(*line) + ft_strlen(buffer) + 1;
	if (!(*line = malloc(sizeof(char) * new_line_len)))
		return (0);
	ft_strcpy(*line, old_line);
	ft_strcpy(*line + ft_strlen(*line), buffer);
	free(old_line);
	return (1);
}
