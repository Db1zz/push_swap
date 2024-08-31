/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/26 14:30:59 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:50:48 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	rotate_stack(t_node **stack_first)
{
	t_node	*stack_last;
	t_node	*new_first;

	if (!*stack_first || !(*stack_first)->next)
		return (false);
	stack_last = get_last_node(*stack_first);
	new_first = (*stack_first)->next;
	stack_last->next = *stack_first;
	(*stack_first)->last = stack_last;
	(*stack_first)->next = NULL;
	new_first->last = NULL;
	*stack_first = new_first;
	return (true);
}

bool	rev_rotate_stack(t_node **stack_first)
{
	t_node	*stack_last;
	t_node	*second_last;

	if (!*stack_first || !(*stack_first)->next)
		return (false);
	stack_last = get_last_node(*stack_first);
	second_last = stack_last->last;
	second_last->next = NULL;
	stack_last->next = *stack_first;
	stack_last->last = NULL;
	(*stack_first)->last = stack_last;
	*stack_first = stack_last;
	return (true);
}

void	rotate_stack_a(t_stack *s, int64_t rotations)
{
	if (rotations < 0)
	{
		while (rotations++ != 0)
			rra(s);
	}
	else if (rotations > 0)
	{
		while (rotations-- != 0)
			ra(s);
	}
}

void	rotate_stack_b(t_stack *s, int64_t rotations)
{
	if (rotations < 0)
	{
		while (rotations++ != 0)
			rrb(s);
	}
	else if (rotations > 0)
	{
		while (rotations-- != 0)
			rb(s);
	}
}
