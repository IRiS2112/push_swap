/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 put_target_a.c 									:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/14 16:02:02 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:18:50 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

t_stack	*find_min(t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *a;
	min = tmp;
	tmp = tmp->next;
	while (tmp)
	{
		if (tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

static int	_is_max(int value, t_stack **a)
{
	t_stack	*tmp;

	tmp = *a;
	while (tmp)
	{
		if (value < tmp->value)
			return (0);
		tmp = tmp->next;
	}
	return (1);
}

static t_stack	*find_target_a(int value, t_stack **a)
{
	t_stack	*tmp;
	t_stack	*min;

	tmp = *a;
	while (tmp)
	{
		if (tmp->value > value)
		{
			min = tmp;
			break ;
		}
		tmp = tmp->next;
	}
	while (tmp)
	{
		if (tmp->value > value && tmp->value < min->value)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}

void	put_target_a(t_stack *tmp, t_stack **a)
{
	if (_is_max(tmp->value, a))
		tmp->target = find_min(a);
	else
		tmp->target = find_target_a(tmp->value, a);
}
