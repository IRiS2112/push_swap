/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:50:32 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 13:13:53 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

void	free_str1(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	while (i > 0)
	{
		i--;
		free (str[i]);
	}
	free (str);
}

static void	free_stack_abi(t_stack **stack)
{
	t_stack	*tmp;

	if (!stack)
		return ;
	while (*stack)
	{
		tmp = (*stack)->next;
		free(*stack);
		*stack = tmp;
	}
}

void	free_stack(t_stack **a, t_stack **b, t_stack **inst)
{
	free_stack_abi(a);
	free_stack_abi(b);
	free_stack_abi(inst);
}