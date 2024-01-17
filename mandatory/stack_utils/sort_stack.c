/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 sort_stack.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/07 18:18:51 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:19:02 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

static void	sort_three(t_stack **a)
{
	if (!s_issort(*a))
	{
		if ((*a)->value < ((*a)->next)->value)
		{
			if ((*a)->value < (((*a)->next)->next)->value)
			{
				swap(a, 'a');
				rotate(a, 'a');
			}
			else
				reverse_rotate(a, 'a');
		}
		else if ((*a)->value > ((*a)->next)->value)
		{
			if ((*a)->value < (((*a)->next)->next)->value)
				swap(a, 'a');
			else
			{
				rotate(a, 'a');
				if (s_issort(*a))
					return ;
				swap(a, 'a');
			}
		}
	}
}

static void	sort_four(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	put_index(a);
	while (tmp && tmp->i_value != 0)
		tmp = tmp->next;
	if (tmp->i_stack == 1)
		swap(a, 'a');
	else if (tmp->i_stack > 1)
	{
		while (tmp->i_stack != 0)
		{
			reverse_rotate(a, 'a');
			in_stack(a);
		}
	}
	if (!s_issort(*a))
	{
		push(b, a, 'b');
		sort_three(a);
		push(a, b, 'a');
	}
}

static void	sort_five(t_stack **a, t_stack **b)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp && tmp->i_value != 0)
		tmp = tmp->next;
	if (tmp->i_stack == 1)
		swap(a, 'a');
	else if (tmp->i_stack > 1)
	{
		while (tmp->i_stack != 0)
		{
			reverse_rotate(a, 'a');
			in_stack(a);
		}
	}
	if (!s_issort(*a))
	{
		push(b, a, 'b');
		sort_four(a, b);
		push(a, b, 'a');
	}
}

void	sort_stack(t_stack **a, t_stack **b)
{
	int	i;

	i = stack_node(*a);
	if (i == 2)
		swap(a, 'a');
	else if (i == 3)
		sort_three(a);
	else if (i == 4)
		sort_four(a, b);
	else if (i == 5)
		sort_five(a, b);
	else
	{
		sort_to_b(a, b);
		sort_three(a);
		sort_to_a(a, b);
	}
}
