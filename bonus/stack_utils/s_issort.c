/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   s_issort.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:00:28 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 11:46:47 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "../checker_bonus.h"

int	s_issort(t_stack *a)
{
	int	i;
	int	j;

	while (a)
	{
		i = 0;
		j = 0;
		i = a->value;
		if (!a->next)
			return (1);
		a = a->next;
		j = a->value;
		if (i > j)
			return (0);
	}
	return (1);
}