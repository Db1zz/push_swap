/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tests.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:07:59 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 20:39:46 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

int	main(void)
{
	t_node	*stack;

	stack = alloc_stack(10);
	if (stack)
	{
		print_stack(stack);
		free_stack(stack);	
	}
	return (0);
}
