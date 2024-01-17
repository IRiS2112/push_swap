/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 put_everything.c									:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/14 10:56:06 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 20:09:21 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	put_everything_b(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	put_index(a);
	put_index(b);
	tmp = *a;
	while (tmp)
	{
		if (tmp->i_stack < stack_node(*a) / 2)
			tmp->med = 1;
		else
			tmp->med = 0;
		put_target_b(tmp, b);
		if (tmp->target->i_stack < stack_node(*b) / 2)
			tmp->target->med = 1;
		else
			tmp->target->med = 0;
		tmp->cheap = put_cheap_a(tmp, tmp->target, a, b);
		tmp = tmp->next;
	}
}

void	put_everything_a(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	put_index(a);
	put_index(b);
	tmp = *b;
	while (tmp)
	{
		if (tmp->i_stack < stack_node(*b) / 2)
			tmp->med = 1;
		else
			tmp->med = 0;
		put_target_a(tmp, a);
		if (tmp->target->i_stack < stack_node(*a) / 2)
			tmp->target->med = 1;
		else
			tmp->target->med = 0;
		tmp->cheap = put_cheap_b(tmp, tmp->target, b, a);
		tmp = tmp->next;
	}
}
