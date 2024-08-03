/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:56 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 09:20:44 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **stack_frist, t_node **stack_second)
{
	if (!*stack_frist || !*stack_second)
		return ;
	*stack_frist = *stack_second;
	(*stack_frist)->last->next = (*stack_frist)->next;
	(*stack_frist)->next = (*stack_frist)->last;
	(*stack_frist)->last = NULL;
	(*stack_frist)->next->last = *stack_frist;
}
