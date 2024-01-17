/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 put_index.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/10 10:43:57 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:18:40 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	in_stack(t_stack **stack_ab)
{
	t_stack	*tmp;
	int		i;

	tmp = *stack_ab;
	i = 0;
	while (tmp)
	{
		tmp->i_stack = i;
		i++;
		tmp = tmp->next;
	}
}

void	in_value(t_stack **stack_ab)
{
	t_stack	*tmp;
	t_stack	*stack;
	int		j;

	stack = *stack_ab;
	while (stack)
	{
		j = 0;
		tmp = *stack_ab;
		while (tmp)
		{
			if (stack->value > tmp->value)
				j++;
			tmp = tmp->next;
		}
		stack->i_value = j;
		stack = stack->next;
	}
}

void	put_index(t_stack **stack)
{
	in_stack(stack);
	in_value(stack);
}
