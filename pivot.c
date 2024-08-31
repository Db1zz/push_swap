/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pivot.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:02:34 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:38:18 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_pivot	*analyze_pivot(t_node *stack_start, size_t chunk_size, t_node *pivot)
{
	t_pivot			*result;
	const t_node	*end = get_node_at_index(stack_start, chunk_size - 1);

	if (!stack_start || !pivot)
		return (NULL);
	result = (t_pivot *)ft_calloc(1, sizeof(t_pivot));
	if (!result)
	{
		ft_printf("ERROR: buy more ram lol\n");
		return (NULL);
	}
	result->pivot = pivot;
	while (stack_start != end->next)
	{
		if (stack_start->data >= pivot->data)
			result->bigger_equals++;
		if (stack_start->data <= pivot->data)
			result->smaller_equals++;
		stack_start = stack_start->next;
	}
	return (result);
}

bool	choose_this_pivot(t_pivot *p, size_t chunk_size)
{
	int	optimal_pivot;

	if (chunk_size % 2 == 0)
		optimal_pivot = chunk_size / 2 + 1;
	else
		optimal_pivot = chunk_size / 2;
	if (p->smaller_equals == optimal_pivot || p->bigger_equals == optimal_pivot)
		return (true);
	return (false);
}

t_pivot	*get_pivot(t_node *stack_start, size_t size)
{
	t_pivot	*result;
	t_node	*curr;
	int		i;

	if (!stack_start)
		return (NULL);
	i = 0;
	while (i < (int)size)
	{
		curr = get_node_at_index(stack_start, i);
		result = analyze_pivot(stack_start, size, curr);
		if (choose_this_pivot(result, size))
			break ;
		i++;
	}
	return (result);
}
