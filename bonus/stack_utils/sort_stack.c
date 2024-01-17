/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 17:03:20 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 12:14:40 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"


static void sort_it(t_stack **a, t_stack **b, t_stack **inst)
{
	if ((*inst)->value == 0)
		push(a, b);
	else if ((*inst)->value == 1)
		push(b, a);
	else if ((*inst)->value == 10)
		swap(a);
	else if ((*inst)->value == 11)
		swap(b);
	else if ((*inst)->value == 12)
		s_swap(a, b);
	else if ((*inst)->value == 20)
		rotate(a);
	else if ((*inst)->value == 21)
		rotate(b);
	else if ((*inst)->value == 22)
		r_rotate(a, b);
	else if ((*inst)->value == 30)
		reverse_rotate(a);
	else if ((*inst)->value == 31)
		reverse_rotate(b);
	else if ((*inst)->value == 32)
		rr_rotate(a, b);
}
			
void	sort_stack(t_stack **a, t_stack **b, t_stack **inst)
{
	t_stack *tmp;

	tmp = *inst;
	while(tmp)
	{
		sort_it(a, b, &tmp);
		tmp = tmp->next;
	}
}