/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 15:10:41 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/15 20:26:49 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int	check_space(int ac, char **av)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		j = 0;
		while (av[i][j])
			j++;
		while (av[i][k] && (av[i][k] == '\t' || av[i][k] == '\n'
			|| av[i][k] == ' ' || av[i][k] == '\v'
			|| av[i][k] == '\f' || av[i][k] == '\r'))
			k++;
		if (j == 0 || k == j)
			return (1);
		i++;
	}
	return (0);
}

static int	check_int(char **str)
{
	int	i;
	int	j;

	i = -1;
	while (str[++i])
	{
		j = 0;
		if (str[i][j] == '-' || str[i][j] == '+')
			j++;
		if (!str[i][j] || str[i][j] < '0' || str[i][j] > '9')
			return (1);
		while (str[i][j])
		{
			if (str[i][j] < '0' || str[i][j] > '9')
				return (1);
			j++;
		}
	}
	return (0);
}

static int	check_minmax(char **str)
{
	int	i;
	int	s;

	i = -1;
	while (str[++i])
	{
		s = 1;
		if (check_m(str[i], s))
			return (1);
	}
	return (0);
}

static int	check_repeat(char **str)
{
	int	i1;
	int	i2;
	int	j;
	int	k;

	i1 = -1;
	while (str[++i1])
	{
		i2 = i1;
		while (str[++i2])
		{
			j = 0;
			k = 0;
			while (str[i1][j] && str[i2][j])
			{
				if (str[i1][j] != str[i2][j])
					k = 1;
				j++;
			}
			if (k == 0 && ft_strlen(str[i1]) == ft_strlen(str[i2]))
				return (1);
		}
	}
	return (0);
}

int	ft_check(int ac, char **av)
{
	char	**str;

	if (check_space(ac, av))
		return (1);
	str = ft_split(ft_strjoin(ac, av), ' ');
	if (check_int(str))
	{
		free_str1(str);
		return (1);
	}
	str = ft_atoa(str);
	if (check_minmax(str) || check_repeat(str))
	{
		free_str1(str);
		return (1);
	}
	free_str1(str);
	return (0);
}