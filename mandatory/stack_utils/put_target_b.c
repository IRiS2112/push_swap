/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 put_target_b.c 									:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/14 11:37:20 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:18:54 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

static t_stack	*find_max(t_stack **b)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *b;
	max = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

static t_stack	*find_target_b(int value, t_stack **b)
{
	t_stack	*tmp;
	t_stack	*max;

	tmp = *b;
	while (tmp)
	{
		if (tmp->value < value)
		{
			max = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->value < value && tmp->value > max->value)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}

static int	_is_min(int value, t_stack **b)
{
	t_stack	*tmp;

	tmp = *b;
	while (tmp)
	{
		if (value > tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

void	put_target_b(t_stack *tmp, t_stack **b)
{
	if (_is_min(tmp->value, b))
		tmp->target = find_max(b);
	else
		tmp->target = find_target_b(tmp->value, b);
}
