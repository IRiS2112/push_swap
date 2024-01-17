/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/15 13:02:08 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 14:54:24 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker_bonus.h"

int main(int ac, char **av)
{	
	t_stack	*a;
	t_stack	*b;
	t_stack *inst;

	inst = NULL;
	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!ft_check(ac, av))
	{
		av = ft_atoa(ft_split(ft_strjoin(ac, av), ' '));
		put_stack(&a, av);
		free_str1(av);
		if(put_inst(&inst))
			return (free_stack(&a, &b, &inst), ft_putendl_fd("Error", 2), 1);
		sort_stack(&a, &b, &inst);
		if (!s_issort(a) || !b_empty(b))
			return (free_stack(&a, &b, &inst), ft_putendl_fd("KO", 1), 0);
		return (free_stack(&a, &b, &inst), ft_putendl_fd("OK", 1), 0);
	}
	return (ft_putendl_fd("Error", 2), 1);
}
