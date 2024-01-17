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

#include "../checker_bonus.h"

void	push(t_stack **dest, t_stack **src)
{
	t_stack	*tmp;

	if (!src || !(*src))
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
}
