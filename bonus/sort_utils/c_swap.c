/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 c_swap.c											:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/07 18:33:45 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:36:54 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	swap(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack || !(*stack))
		return ;
	if (stack_node(*stack) >= 2)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
}

void s_swap(t_stack **a, t_stack **b)
{
	swap(a);
	swap(b);
}
