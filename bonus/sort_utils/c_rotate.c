/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 c_rotate.c 										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/08 18:11:34 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:35:16 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*sec;

	if (!stack || !(*stack))
		return ;
	if (stack_node(*stack) >= 2)
	{
		last = *stack;
		sec = last->next;
		while (last->next)
			last = last->next;
		last->next = *stack;
		(*stack)->next = NULL;
		*stack = sec;
	}
}

void	r_rotate(t_stack **a, t_stack **b)
{
	rotate(a);
	rotate(b);
}
