/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 sort_to_a.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/14 15:53:28 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:25:51 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	sort_to_a(t_stack **a, t_stack **b)
{
	t_stack	*cheapest;
	t_stack	*min;

	while (*b)
	{
		put_everything_a(a, b);
		cheapest = find_cheapest(*b);
		move_top_b(cheapest, b, a);
		push(a, b, 'a');
	}
	min = find_min(a);
	if (min->i_stack < stack_node(*a) / 2)
		while (min->value != (*a)->value)
			rotate(a, 'a');
	else
		while (min->value != (*a)->value)
			reverse_rotate(a, 'a');
}
