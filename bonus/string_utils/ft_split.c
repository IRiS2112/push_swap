/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:47:13 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/15 20:47:33 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static size_t	count_words(const char *str, char c)
{
	int		i;
	size_t	t;

	i = 0;
	if (str[i] == '\0')
		return (0);
	while (str[i] == c)
		i++;
	i = 1;
	t = 0;
	while (str[i])
	{
		if (str[i] == c && str[i - 1] != c)
			t++;
		i++;
	}
	if (str[i] == 0 && str[i - 1] != c)
		t++;
	return (t);
}

static size_t	len_word(char const *s, char c)
{
	size_t	i;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

static void	free_str(size_t i, char **str)
{
	while (i > 0)
	{
		i--;
		free(str[i]);
	}
	free(str);
}

static char	**w_word(char *s, char c, char **str, size_t n)
{
	size_t	i;
	size_t	j;

	j = 0;
	i = 0;
	while (i < n)
	{
		while (s[j] && s[j] == c)
			j++;
		str[i] = ft_substr(s, j, len_word(&s[j], c));
		if (!str[i])
		{
			free_str(i, str);
			return (0);
		}
		while (s[j] && s[j] != c)
			j++;
		i++;
	}
	str[i] = 0;
	return (str);
}

char	**ft_split(char *s, char c)
{
	size_t	n;
	char	**str;

	if (!s)
		return (0);
	n = count_words(s, c);
	str = (char **)malloc(sizeof(char *) * (n + 1));
	if (!str)
		return (0);
	str = w_word(s, c, str, n);
	return (free(s), str);
}