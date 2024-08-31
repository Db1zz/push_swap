/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 19:36:19 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 02:24:37 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_stack	*stack;
	size_t	stack_size;

	if (argc >= 2)
	{
		stack = init_stack(argv + 1);
		if (stack)
		{
			stack_size = get_list_size(stack->stack_a);
			if (stack_size <= 5)
				simple_sort(stack, stack_size);
			else
			{
				sort(stack);
				rotate_stack_a(stack, get_path_to_value_in_list(stack->stack_a,
						get_smallest_val_in_lst(stack->stack_a)->data));
			}
			free_stack(&stack);
		}
	}
	return (0);
}
