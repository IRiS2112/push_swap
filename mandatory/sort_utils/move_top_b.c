/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_top_b.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 16:23:22 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/14 20:09:10 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

static void	loup_rr_a(t_stack *cheapest, t_stack **b, t_stack **a)
{
	while (cheapest->value != (*b)->value
		&& cheapest->target->value != (*a)->value)
		r_rotate(b, a);
	while (cheapest->value != (*b)->value)
		rotate(b, 'b');
	while (cheapest->target->value != (*a)->value)
		rotate(a, 'a');
}

static void	loup_rrr_a(t_stack *cheapest, t_stack **b, t_stack **a)
{
	while (cheapest->value != (*b)->value
		&& cheapest->target->value != (*a)->value)
		rr_rotate(b, a);
	while (cheapest->value != (*b)->value)
		reverse_rotate(b, 'b');
	while (cheapest->target->value != (*a)->value)
		reverse_rotate(a, 'a');
}

static void	loop_single_a(t_stack *cheapest, t_stack **b, t_stack **a)
{
	if (cheapest->med == 1 && cheapest->target->med == 0)
	{
		while (cheapest->value != (*b)->value)
			rotate(b, 'b');
		while (cheapest->target->value != (*a)->value)
			reverse_rotate(a, 'a');
	}
	else if (cheapest->med == 0 && cheapest->target->med == 1)
	{
		while (cheapest->value != (*b)->value)
			reverse_rotate(b, 'b');
		while (cheapest->target->value != (*a)->value)
			rotate(a, 'a');
	}
}

void	move_top_b(t_stack *cheapest, t_stack **b, t_stack **a)
{
	if (cheapest->med == 1 && cheapest->target->med == 1)
		loup_rr_a(cheapest, b, a);
	else if (cheapest->med == 0 && cheapest->target->med == 0)
		loup_rrr_a(cheapest, b, a);
	else
		loop_single_a(cheapest, b, a);
}
