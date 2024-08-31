/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:51:14 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:02:06 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*get_last_node(t_node *list)
{
	if (!list)
		return (NULL);
	while (list->next)
		list = list->next;
	return (list);
}

t_node	*get_node_at_index(t_node *list, size_t index)
{
	if (!list)
		return (NULL);
	while (index-- > 0 && list->next)
		list = list->next;
	return (list);
}

t_node	*get_biggest_val_in_lst(t_node *list)
{
	t_node	*result;

	if (!list)
		return (0);
	result = list;
	while (list)
	{
		if (list->data > result->data)
			result = list;
		list = list->next;
	}
	return (result);
}

t_node	*get_smallest_val_in_lst(t_node *list)
{
	t_node	*result;

	if (!list)
		return (0);
	result = list;
	while (list)
	{
		if (list->data < result->data)
			result = list;
		list = list->next;
	}
	return (result);
}

size_t	get_list_size(t_node *list)
{
	size_t	result;

	result = 0;
	while (list)
	{
		result++;
		list = list->next;
	}
	return (result);
}
