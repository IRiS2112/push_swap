/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/20 14:37:06 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/16 19:54:59 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

size_t	ft_strlen_g(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

static void	ft_bzero(void *s, size_t n)
{
	size_t	i;
	char	*str;

	i = 0;
	str = (char *)s;
	while (i < n)
	{
		str[i] = 0;
		i++;
	}
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*str;

	str = malloc(count * size);
	if (!str)
		return (0);
	ft_bzero(str, count * size);
	return (str);
}

char	*ft_strchr(const char *s, int c)
{
	while (*s)
	{
		if (*s == (char)c)
			return ((char *)s);
		s++;
	}
	if (*s == (char)c)
		return ((char *)s);
	return (0);
}

char	*ft_strjoin_g(char const *s1, char const *s2)
{
	char	*str;
	int		b;

	if (!s1 || !s2)
		return (NULL);
	str = (char *)malloc(ft_strlen_g(s1) + ft_strlen_g(s2) + 1);
	if (!str)
		return (0);
	b = 0;
	while (*s1)
	{
		str[b] = *s1;
		s1++;
		b++;
	}
	while (*s2)
	{
		str[b] = *s2;
		b++;
		s2++;
	}
	str[b] = 0;
	return (str);
}
