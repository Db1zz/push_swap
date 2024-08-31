/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:53 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:33:31 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	push_stack(t_node **push_from, t_node **push_to)
{
	t_node	*temp;

	if (!(*push_from))
		return (false);
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
	return (true);
}

void	pa(t_stack *s)
{
	if (push_stack(&s->stack_b, &s->stack_a))
		ft_printf("%s\n", __func__);
}

void	pb(t_stack *s)
{
	if (push_stack(&s->stack_a, &s->stack_b))
		ft_printf("%s\n", __func__);
}

void	push_a(t_stack *stack)
{
	while (stack->stack_b)
		pa(stack);
}
