/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_cheap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/14 12:21:44 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/14 20:25:44 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../push_swap.h"

int	put_cheap_a(t_stack *tmp, t_stack *target, t_stack **a, t_stack **b)
{
	if (tmp->med == 1 && target->med == 1)
	{
		if (tmp->i_stack <= target->i_stack)
			return (target->i_stack);
		else
			return (tmp->i_stack);
	}
	if (tmp->med == 0 && target->med == 0)
	{
		if (stack_node(*a) - tmp->i_stack <= stack_node(*b) - target->i_stack)
			return (stack_node(*b) - target->i_stack);
		else
			return (stack_node(*a) - tmp->i_stack);
	}
	else if (tmp->med == 1 && target->med == 0)
		return (tmp->i_stack + stack_node(*b) - target->i_stack);
	else
		return (stack_node(*a) - tmp->i_stack + target->i_stack);
}

int	put_cheap_b(t_stack *tmp, t_stack *target, t_stack **b, t_stack **a)
{
	if (tmp->med == 1 && target->med == 1)
	{
		if (tmp->i_stack <= target->i_stack)
			return (target->i_stack);
		else
			return (tmp->i_stack);
	}
	if (tmp->med == 0 && target->med == 0)
	{
		if (stack_node(*b) - tmp->i_stack <= stack_node(*a) - target->i_stack)
			return (stack_node(*a) - target->i_stack);
		else
			return (stack_node(*b) - tmp->i_stack);
	}
	else if (tmp->med == 1 && target->med == 0)
		return (tmp->i_stack + stack_node(*a) - target->i_stack);
	else
		return (stack_node(*b) - tmp->i_stack + target->i_stack);
}

t_stack	*find_cheapest(t_stack *stack)
{
	t_stack	*tmp;
	t_stack	*cheapest;

	cheapest = stack;
	tmp = stack;
	while (tmp)
	{
		if (cheapest->cheap > tmp->cheap)
			cheapest = tmp;
		tmp = tmp->next;
	}
	return (cheapest);
}
