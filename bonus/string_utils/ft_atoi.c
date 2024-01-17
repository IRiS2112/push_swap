/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 20:45:33 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/15 20:45:44 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static char	*ft_atoa1(char *str)
{
	int	j;
	int	k;

	j = 0;
	k = 0;
	if (str[j] && (str[j] == '-' || str[j] == '+'))
	{
		if (str[j] == '-')
			k++;
		j++;
	}
	while (str[j] && str[j] == '0')
		j++;
	if (!str[j])
		str[k++] = '0';
	while (str[j])
		str[k++] = str[j++];
	if (str[0] == '-' && str[1] == '0')
	{
		str[0] = '0';
		k = 1;
	}
	str[k] = 0;
	return (str);
}

char	**ft_atoa(char **str)
{
	int	i;

	i = -1;
	while (str[++i])
		str[i] = ft_atoa1(str[i]);
	return (str[i] = 0, str);
}

int	ft_atoi(char *str)
{
	int	c;
	int	sign;

	while ((*str != '\0')
		&& ((*str >= 9 && *str <= 13) || *str == 32))
		str++;
	sign = 1;
	if ((*str != '\0')
		&& (*str == '+' || *str == '-'))
	{
		if (*str == '-')
			sign = sign * -1;
		str++;
	}
	c = 0;
	while ((*str != '\0')
		&& (*str >= '0' && *str <= '9'))
	{
		c = c * 10 + (*str - '0');
		str++;
	}
	return (c * sign);
}