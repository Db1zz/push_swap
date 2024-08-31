/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/24 18:53:40 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:20:20 by gonische         ###   ########.fr       */
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

void	free_node(t_node **node)
{
	t_node	*curr;

	if (!node || !(*node))
		return ;
	curr = *node;
	if ((*node)->last)
		(*node)->last->next = (*node)->next;
	if ((*node)->next)
		(*node)->next->last = (*node)->last;
	if ((*node)->last && (*node)->next)
		*node = (*node)->next;
	else if ((*node)->last)
		*node = (*node)->last;
	else if ((*node)->next)
		*node = (*node)->next;
	else
		*node = NULL;
	free(curr);
}

int	get_path_to_value_in_list(t_node *list, int value)
{
	int		result;
	size_t	list_size;

	result = 0;
	list_size = get_list_size(list);
	while (list)
	{
		if (list->data == value)
		{
			if (!((int)(list_size / 2) >= result))
				result = -((int)list_size - result);
			return (result);
		}
		result++;
		list = list->next;
	}
	return (INT_MAX);
}
