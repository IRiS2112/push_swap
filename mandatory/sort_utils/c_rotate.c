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

#include "../push_swap.h"

void	rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*sec;

	if (!stack)
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
	if (c == 'a')
		ft_putendl_fd("ra", 1);
	else if (c == 'b')
		ft_putendl_fd("rb", 1);
}

void	r_rotate(t_stack **a, t_stack **b)
{
	rotate(a, 'n');
	rotate(b, 'n');
	ft_putendl_fd("rr", 1);
}
