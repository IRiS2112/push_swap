/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   b_empty.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hakaraou <hakaraou@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/17 11:49:22 by hakaraou          #+#    #+#             */
/*   Updated: 2024/01/17 13:16:55 by hakaraou         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../checker_bonus.h"

int b_empty(t_stack *b)
{
	t_stack *tmp;

	if(!b)
		return(1);
	tmp = b;
	if(stack_node(b) == 0)
		return (1);
	return (0);
}