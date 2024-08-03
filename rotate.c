/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 09:20:50 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	rotate_stack(t_node **stack_first, t_node **stack_last)
{
	(*stack_last)->next = (*stack_first);
	(*stack_first)->last = (*stack_last);
	(*stack_last) = (*stack_first);
	(*stack_first) = (*stack_first)->next;
	(*stack_last)->next = NULL;
	(*stack_first)->last = NULL;
}
