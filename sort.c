/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:03:32 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 02:22:27 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_chunk(t_stack *s, size_t chunk_size)
{
	int	path;

	if (!s->stack_b)
	{
		while (chunk_size-- != 0)
			pb(s);
	}
	while (s->stack_b)
	{
		path = get_path_to_value_in_list(s->stack_b,
				get_biggest_val_in_lst(s->stack_b)->data);
		rotate_stack_b(s, path);
		pa(s);
	}
}

void	sort(t_stack *s)
{
	t_pivot	*pivot;
	t_node	*chunks_list;
	t_node	*curr_chunk;

	chunks_list = alloc_node(NULL, NULL, get_list_size(s->stack_a));
	curr_chunk = chunks_list;
	while (!are_chunks_sorted(chunks_list, curr_chunk, s->stack_a))
	{
		if (is_chunk_sorted(s->stack_a, curr_chunk->data))
		{
			rotate_stack_a(s, curr_chunk->data);
			next_chunk(&chunks_list, &curr_chunk);
		}
		else if (curr_chunk->data <= SORT_THRESHOLD)
			sort_chunk(s, curr_chunk->data);
		else
		{
			pivot = get_pivot(s->stack_a, curr_chunk->data);
			split_chunk(&chunks_list, &curr_chunk, s, pivot);
			free(pivot);
		}
	}
	free_list(chunks_list);
}
