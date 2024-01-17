/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 move_top_a.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/14 14:39:22 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:40:33 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

static void	loup_rr_b(t_stack *cheapest, t_stack **a, t_stack **b)
{
	while (cheapest->value != (*a)->value
		&& cheapest->target->value != (*b)->value)
		r_rotate(a, b);
	while (cheapest->value != (*a)->value)
		rotate(a, 'a');
	while (cheapest->target->value != (*b)->value)
		rotate(b, 'b');
}

static void	loup_rrr_b(t_stack *cheapest, t_stack **a, t_stack **b)
{
	while (cheapest->value != (*a)->value
		&& cheapest->target->value != (*b)->value)
		rr_rotate(a, b);
	while (cheapest->value != (*a)->value)
		reverse_rotate(a, 'a');
	while (cheapest->target->value != (*b)->value)
		reverse_rotate(b, 'b');
}

static void	loop_single_b(t_stack *cheapest, t_stack **a, t_stack **b)
{
	if (cheapest->med == 1 && cheapest->target->med == 0)
	{
		while (cheapest->value != (*a)->value)
			rotate(a, 'a');
		while (cheapest->target->value != (*b)->value)
			reverse_rotate(b, 'b');
	}
	else if (cheapest->med == 0 && cheapest->target->med == 1)
	{
		while (cheapest->value != (*a)->value)
			reverse_rotate(a, 'a');
		while (cheapest->target->value != (*b)->value)
			rotate(b, 'b');
	}
}

void	move_top_a(t_stack *cheapest, t_stack **a, t_stack **b)
{
	if (cheapest->med == 1 && cheapest->target->med == 1)
		loup_rr_b(cheapest, a, b);
	else if (cheapest->med == 0 && cheapest->target->med == 0)
		loup_rrr_b(cheapest, a, b);
	else
		loop_single_b(cheapest, a, b);
}
