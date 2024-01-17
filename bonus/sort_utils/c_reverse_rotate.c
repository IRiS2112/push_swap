/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 c_reverse_rotate.c 								:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/09 12:55:06 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:33:05 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	reverse_rotate(t_stack **stack)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	if (stack_node(*stack) >= 2)
	{
		tmp = *stack;
		while ((tmp->next)->next)
			tmp = tmp->next;
		last = tmp->next;
		tmp->next = NULL;
		last->next = *stack;
		*stack = last;
	}
}

void	rr_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate(a);
	reverse_rotate(b);
}
