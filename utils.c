/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 18:00:04 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 18:07:49 by gonische         ###   ########.fr       */
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
