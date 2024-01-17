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

#include "../push_swap.h"

void	reverse_rotate(t_stack **stack, char c)
{
	t_stack	*last;
	t_stack	*tmp;

	if (!stack)
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
	if (c == 'a')
		ft_putendl_fd("rra", 1);
	else if (c == 'b')
		ft_putendl_fd("rrb", 1);
}

void	rr_rotate(t_stack **a, t_stack **b)
{
	reverse_rotate(a, 'n');
	reverse_rotate(b, 'n');
	ft_putendl_fd("rrr", 1);
}
