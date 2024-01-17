/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   put_inst.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/16 16:04:45 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 14:20:25 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

static int conv_ti(char *line)
{
	if (ft_strcmp(line, "pa"))
		return (0);
	if (ft_strcmp(line, "pb"))
		return (1);
	else if (ft_strcmp(line, "sa"))
		return (10);
	else if (ft_strcmp(line, "sb"))
		return (11);
	else if (ft_strcmp(line, "ss"))
		return (12);
	else if (ft_strcmp(line, "ra"))
		return (20);
	else if (ft_strcmp(line, "rb"))
		return (21);
	else if (ft_strcmp(line, "rr"))
		return (22);
	else if (ft_strcmp(line, "rra"))
		return (30);
	else if (ft_strcmp(line, "rrb"))
		return (31);
	else if (ft_strcmp(line, "rrr"))
		return (32);
	return (-1);
}

static t_stack	*find_l_node(t_stack *last)
{
	if (!last)
		return (NULL);
	while (last->next)
		last = last->next;
	return (last);
}

static void put_inst2(t_stack **inst, int nb)
{
	t_stack	*node;
	t_stack	*l_node;

	if (!inst)
		return ;
	node = malloc(sizeof(t_stack));
	if (!node)
		return ;
	node->next = NULL;
	node->value = nb;
	if (!(*inst))
		*inst = node;
	else
	{
		l_node = find_l_node(*inst);
		l_node->next = node;
	}
}

static int put_inst1(t_stack **inst, char *line)
{
	int nb;
	nb = conv_ti(line);
	if (nb == -1)
		return (0);
	put_inst2(inst, nb);
	return(1);
}


int put_inst(t_stack **inst)
{
	char *line;
	
	line = get_next_line(0);
	while (line)
	{
		if(!put_inst1(inst, line))
			return (1);
		free(line);
		line = get_next_line(0);
	}
	return (0);
}