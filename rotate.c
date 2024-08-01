/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 19:45:38 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack_first, t_node **stack_last)
{
	swap_node(stack_first, stack_last);
	(*stack_first)->next = (*stack_last)->next;
	(*stack_last)->last = (*stack_first)->last;
	(*stack_first)->last = NULL;
	(*stack_last)->next = NULL;
}
