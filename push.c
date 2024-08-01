/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:53 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 20:59:36 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*
	TEST THIS CODE PLEASE
*/
void	push_stack(t_node **stack_a, t_node **stack_b)
{
	t_node	*temp;

	if (!(*stack_a))
		return ;
	temp = (*stack_a)->next;
	if (*stack_b)
	{
		(*stack_a)->next = *stack_b;
		(*stack_b)->last = (*stack_a);
		*stack_b = *stack_a;
	}
	else
	{
		*stack_b = *stack_a;
		(*stack_a)->next = NULL;
	}
	*stack_a = temp;
}
