/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:36:15 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 13:46:49 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static char	*ft_get_next(char *buffer)
{
	char	*line;
	int		i;
	int		j;

	i = 0;
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (!buffer[i])
		return (free(buffer), NULL);
	line = ft_calloc(sizeof(char), (ft_strlen_g(buffer) - i));
	if (!line)
		return (free(buffer), NULL);
	j = 0;
	while (buffer[++i])
		line[j++] = buffer[i];
	return (free(buffer), line);
}

static char	*ft_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!buffer[i])
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = ft_calloc(sizeof(char), i + 1);
	if (!line)
		return (NULL);
	i = -1;
	while (buffer[++i] && buffer[i] != '\n')
		line[i] = buffer[i];
	if (buffer[i] == '\n')
		line[i] = '\n';
	return (line);
}

static char	*ft_add(char *buf, char *str)
{
	char	*buffer;

	if (!buf)
		buf = ft_calloc(1, 1);
	buffer = ft_strjoin_g(buf, str);
	return (free(buf), buffer);
}

static char	*ft_read(int fd, char *buffer)
{
	char	*str;
	int		len;

	str = malloc(sizeof(char) * (4 + 1));
	if (!str)
		return (free (buffer), NULL);
	len = 4;
	while (len == 4)
	{
		len = read(fd, str, 4);
		if (len == -1)
			return (free(buffer), free(str), NULL);
		str[len] = '\0';
		buffer = ft_add(buffer, str);
		if (ft_strchr(str, '\n'))
			break ;
	}
	return (free(str), buffer);
}

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0)
		return (NULL);
	buffer = ft_read(fd, buffer);
	if (!buffer)
		return (NULL);
	line = ft_line(buffer);
	if (!line)
		return (free(buffer), buffer = NULL, NULL);
	buffer = ft_get_next(buffer);
	return (line);
}
