/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:49:04 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/15 20:49:26 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static size_t	ft_strlen1(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(char *s, unsigned int start, size_t len)
{
	char	*s1;
	size_t	j;
	size_t	lens;

	if (!s)
		return (0);
	lens = ft_strlen1(s);
	if (len > lens - start)
		len = lens - start;
	if (start > lens)
		len = 0;
	s1 = (char *)malloc(len + 1);
	if (!s1)
		return (0);
	j = 0;
	while (j < len)
	{
		s1[j] = s[start];
		j++;
		start++;
	}
	s1[j] = 0;
	return (s1);
}