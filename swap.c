/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:56 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:52:41 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

bool	swap_stack(t_node **stack_frist)
{
	t_node	*stack_second;
	t_node	*temp;

	if (!*stack_frist || !(*stack_frist)->next)
		return (false);
	stack_second = (*stack_frist)->next;
	temp = stack_second->next;
	stack_second->next = *stack_frist;
	(*stack_frist)->next = temp;
	stack_second->last = (*stack_frist)->last;
	(*stack_frist)->last = stack_second;
	if (temp)
		temp->last = *stack_frist;
	*stack_frist = stack_second;
	return (true);
}

void	sa(t_stack *s)
{
	if (swap_stack(&s->stack_a))
		ft_printf("%s\n", __func__);
}

void	sb(t_stack *s)
{
	if (swap_stack(&s->stack_b))
		ft_printf("%s\n", __func__);
}
