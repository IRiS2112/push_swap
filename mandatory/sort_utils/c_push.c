/* ************************************************************************** */
/*																			  */
/*														  :::	   ::::::::   */
/*	 c_push.c											:+: 	 :+:	:+:   */
/*													  +:+ +:+		  +:+	  */
/*	 By: hakaraou <hakaraou@student.42.fr>			+#+  +:+	   +#+		  */
/*												  +#+#+#+#+#+	+#+ 		  */
/*	 Created: 2024/01/07 19:03:53 by hakaraou		   #+#	  #+#			  */
/*	 Updated: 2024/01/14 18:30:16 by hakaraou		  ###	########.fr 	  */
/*																			  */
/* ************************************************************************** */

#include "../push_swap.h"

void	push(t_stack **dest, t_stack **src, char c)
{
	t_stack	*tmp;

	if (!src)
		return ;
	tmp = *src;
	*src = (*src)->next;
	if (!(*dest))
	{
		*dest = tmp;
		tmp->next = NULL;
	}
	else
	{
		tmp->next = *dest;
		*dest = tmp;
	}
	if (c == 'a')
		ft_putendl_fd("pa", 1);
	else if (c == 'b')
		ft_putendl_fd("pb", 1);
}
