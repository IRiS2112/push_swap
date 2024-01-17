/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_len.c											:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/10 10:25:26 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:19:32 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	stack_node(t_stack *a)
{
	int	i;

	i = 1;
	while (a->next)
	{
		i++;
		a = a->next;
	}
	return (i);
}
