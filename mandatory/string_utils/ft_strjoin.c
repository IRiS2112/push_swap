/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_strjoin.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/06 15:16:55 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:19:22 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

static size_t	ft_str_len(int ac, char **av)
{
	int		i;
	size_t	j;
	size_t	k;

	i = 0;
	j = 0;
	k = 0;
	while (++i < ac)
	{
		while (av[i][k])
		{
			k++;
			j++;
		}
		k = 0;
		j++;
	}
	return (j);
}

char	*ft_strjoin(int ac, char **av)
{
	char	*str;
	int		i;
	int		b;
	int		j;

	str = (char *)malloc(ft_str_len(ac, av));
	if (!str)
		return (0);
	i = 0;
	b = 0;
	while (++i < ac)
	{
		j = 0;
		while (av[i][j])
		{
			str[b] = av[i][j];
			j++;
			b++;
		}
		str[b] = ' ';
		b++;
	}
	b--;
	str[b] = 0;
	return (str);
}
