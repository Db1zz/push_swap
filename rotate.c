/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/26 14:30:41 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ra(t_stack *s)
{
	if (rotate_stack(&s->stack_a))
		ft_printf("%s\n", __func__);
}

void	rb(t_stack *s)
{
	if (rotate_stack(&s->stack_b))
		ft_printf("%s\n", __func__);
}

void	rra(t_stack *s)
{
	if (rev_rotate_stack(&s->stack_a))
		ft_printf("%s\n", __func__);
}

void	rrb(t_stack *s)
{
	if (rev_rotate_stack(&s->stack_b))
		ft_printf("%s\n", __func__);
}

void	rrr(t_stack *s)
{
	if (rev_rotate_stack(&s->stack_a) || rev_rotate_stack(&s->stack_b))
		ft_printf("%s\n", __func__);
}
