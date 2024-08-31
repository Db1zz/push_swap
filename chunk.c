/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   chunk.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:10:43 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 16:01:52 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	create_chunks(t_node **start, t_node **chunk, size_t lchunk_s,
		size_t rchunk_s)
{
	t_node	*lchunk_p;
	t_node	*rchunk_p;

	lchunk_p = alloc_node(NULL, (*chunk)->last, lchunk_s);
	rchunk_p = alloc_node((*chunk)->next, lchunk_p, rchunk_s);
	lchunk_p->next = rchunk_p;
	if (*start == *chunk)
		*start = lchunk_p;
	if ((*chunk)->last)
		(*chunk)->last->next = lchunk_p;
	if ((*chunk)->next)
		(*chunk)->next->last = rchunk_p;
	free(*chunk);
	*chunk = rchunk_p;
}

void	next_chunk(t_node **chunk_list, t_node **chunk)
{
	if (!(*chunk)->next)
		*chunk = *chunk_list;
	else
		*chunk = (*chunk)->next;
}

bool	analyze_chunk(t_stack *stack, t_node *pivot, size_t chunk_size)
{
	t_node	*s;
	size_t	smaller;
	size_t	bigger;

	smaller = 0;
	bigger = 0;
	s = stack->stack_a;
	while (chunk_size-- > 0 && s)
	{
		if (pivot->data < s->data)
			smaller++;
		else if (pivot->data >= s->data)
			bigger++;
		s = s->next;
	}
	return (bigger > smaller);
}

void	split_chunk(t_node **chunk_list, t_node **chunk, t_stack *s, t_pivot *p)
{
	int		index;
	size_t	size_b;

	if (!s || !p)
		return ;
	index = 0;
	while (index + (int)get_list_size(s->stack_b) <= (*chunk)->data - 1)
	{
		if (s->stack_a->data >= p->pivot->data)
			pb(s);
		else
		{
			ra(s);
			index++;
		}
		if (s->stack_b && s->stack_b->data == p->pivot->data)
			rb(s);
	}
	size_b = get_list_size(s->stack_b);
	create_chunks(chunk_list, chunk, (*chunk)->data - size_b, size_b);
	if (size_b <= SORT_THRESHOLD)
		sort_chunk(s, size_b);
	else
		push_a(s);
}
