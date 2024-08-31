/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:09:01 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:11:10 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

size_t	get_amount_of_chunks(t_node *chunk)
{
	size_t	result;

	result = 0;
	while (chunk != NULL)
	{
		chunk = chunk->next;
		result++;
	}
	return (result);
}

bool	is_chunk_sorted(const t_node *chunk_start, size_t chunk_size)
{
	t_node	*next;
	t_node	*cur;

	cur = (t_node *)chunk_start;
	while ((--chunk_size) != 0)
	{
		next = cur->next;
		if (!((cur && next) && (cur->data <= next->data)))
			return (false);
		cur = next;
	}
	return (true);
}

bool	are_chunks_sorted(t_node *chunk_list, t_node *chunk, t_node *s)
{
	size_t	checked;

	checked = get_amount_of_chunks(chunk_list);
	while (checked != 0)
	{
		if (!is_chunk_sorted(s, chunk->data))
			return (false);
		s = get_node_at_index(s, chunk->data);
		next_chunk(&chunk_list, &chunk);
		checked--;
	}
	return (true);
}
