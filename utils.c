/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:00:04 by gonische          #+#    #+#             */
/*   Updated: 2024/08/02 18:40:38 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*alloc_node(t_node *next, t_node *last, int data)
{
	t_node	*result;
	result = ft_calloc(1, sizeof(t_node));
	if (!result)
		return (NULL);
	result->next = next;
	result->last = last;
	result->data = data;
	return (result);
}

void	swap_node(t_node **a, t_node **b)
{
	t_node	*temp;
	
	temp = *a;
	*a = *b;
	*b = temp;
}
