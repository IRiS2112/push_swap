/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 10:47:47 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/16 11:04:07 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static t_stack	*find_l_node(t_stack *last)
{
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

static void	put_node(t_stack **stack, int nb)
{
	t_stack	*node;
	t_stack	*l_node;

	if (!stack)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nb;
	if (!(*stack))
		*stack = node;
	else
	{
		l_node = find_l_node(*stack);
		l_node->next = node;
	}
}

void	put_stack(t_stack **a, char **av)
{
	int	nb;
	int	i;

	i = 0;
	while (av[i])
	{
		nb = ft_atoi(av[i]);
		put_node(a, nb);
		i++;
	}
}