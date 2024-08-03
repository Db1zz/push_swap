/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:53 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 09:20:57 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_stack(t_node **push_from, t_node **push_to)
{
	t_node	*temp;

	if (!(*push_from))
		return ;
	if (*push_to != NULL)
	{		
		(*push_to)->last = *push_from;
		temp = (*push_from)->next;
		(*push_from)->next = *push_to;
		*push_to = *push_from;
		*push_from = temp;
		if (*push_from)
			(*push_from)->last = NULL;
	}
	else
	{
		*push_to = *push_from;
		*push_from = (*push_from)->next;
		(*push_to)->next = NULL;
	}
}
