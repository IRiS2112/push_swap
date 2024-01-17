/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 sort_to_b.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/13 18:44:36 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:27:07 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_to_b(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;

	push(b, a, 'b');
	push(b, a, 'b');
	while (stack_node(*a) > 3)
	{
		put_everything_b(a, b);
		cheapest = find_cheapest(*a);
		move_top_a(cheapest, a, b);
		push(b, a, 'b');
	}
}
