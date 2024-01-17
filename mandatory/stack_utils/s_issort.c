/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 s_issort.c 										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/07 16:14:48 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:18:57 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

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
