/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:07:59 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 09:21:18 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

void	test_push()
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*last;

	stack_a = alloc_stack(10);
	stack_b = NULL;
	if (stack_a || stack_b)
	{
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		last = get_last_node(stack_b);
		print_backwards(last);
		print_stack(stack_a);
		print_stack(stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
}

void	test_swap()
{
	t_node	*stack_a;
	
	stack_a = alloc_stack(10);
	if (stack_a)
	{
		swap_stack(&stack_a, &stack_a->next);
		print_stack(stack_a);
		free_stack(stack_a);
	}
}

void	test_push_rotate()
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*last;

	stack_a = alloc_stack(3);
	stack_b = NULL;
	if (stack_a)
	{
		push_stack(&stack_a, &stack_b);
		push_stack(&stack_a, &stack_b);
		last = get_last_node(stack_b);
		rotate_stack(&stack_b, &last);
		print_stack(stack_a);
		print_stack(stack_b);
		free_stack(stack_a);
		free_stack(stack_b);
	}
}

void	test_all()
{
	t_node	*stack_a;
	t_node	*stack_b;
	t_node	*last;

	stack_a = alloc_stack(10);
	if (stack_a)
	{
		print_stack(stack_a);
		last = get_last_node(stack_a);
		rotate_stack(&stack_a, &last);
		last = get_last_node(stack_a);
		rotate_stack(&stack_a, &last);
		print_stack(stack_a);
		free_stack(stack_a);
	}
}

int	main(void)
{
	test_push_rotate();
	return (0);
}
