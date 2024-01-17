/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 push_swap.c										:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/06 15:15:02 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:19:39 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int ac, char **av)
{
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	if (ac == 1)
		return (0);
	if (!ft_check(ac, av))
	{
		av = ft_atoa(ft_split(ft_strjoin(ac, av), ' '));
		put_stack(&a, av);
		free_str1(av);
		if (!s_issort(a))
		{
			sort_stack(&a, &b);
			return (free_stack(&a, &b), 0);
		}
		return (free_stack(&a, &b), 0);
	}
	return (ft_putendl_fd("Error", 2), 1);

}
