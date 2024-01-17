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

#include "../push_swap.h"

void	swap(t_stack **stack, char c)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	if (stack_node(*stack) >= 2)
	{
		tmp = (*stack);
		*stack = (*stack)->next;
		tmp->next = (*stack)->next;
		(*stack)->next = tmp;
	}
	if (c == 'a')
		ft_putendl_fd("sa", 1);
	else if (c == 'b')
		ft_putendl_fd("sb", 1);
}
