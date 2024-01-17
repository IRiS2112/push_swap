/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 ft_free.c											:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/09 13:46:18 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:19:29 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	free_str1(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		free (str[i]);
	}
	free (str);
}

static void	free_stack_ab(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_stack(t_stack **a, t_stack **b)
{
	free_stack_ab(a);
	free_stack_ab(b);
}
