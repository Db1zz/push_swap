/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:14:39 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 09:21:05 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test.h"

t_node	*alloc_stack(size_t stack_size)
{
	t_node	*result;
	t_node	*tail;
	size_t	i;

	if (!stack_size)
		return (NULL);
	result = alloc_node(NULL, NULL, 0);
	if (!result)
		return (NULL);
	tail = result;
	i = 1;
	while (i < stack_size)
	{
		tail->next = alloc_node(NULL, tail, i);
		tail = tail->next;
		if (!tail)
		{
			free_stack(result);
			return (NULL);
		}
		i++;
	}
	return (result);
}

void	free_stack(t_node *stack_top)
{
	t_node	*next;

	if (!stack_top)
		return ;	
	while (stack_top)
	{
		next = stack_top->next;
		free(stack_top);
		stack_top = next;
	}
}

void	print_stack(t_node *stack)
{
	if (stack)
		ft_printf("Stack-->");
	while (stack)
	{
		ft_printf("[%d]-->", stack->data);
		stack = stack->next;
	}
	ft_printf("NULL\n");
}

void	print_backwards(t_node *stack_last)
{
	if (stack_last)
		ft_printf("Last-->");
	while (stack_last)
	{
		ft_printf("[%d]-->", stack_last->data);
		stack_last = stack_last->last;
	}
	ft_printf("NULL\n");
}

t_node	*get_last_node(t_node *stack)
{
	if (!stack)
		return (NULL);
	while (stack->next)
		stack = stack->next;
	return (stack);
}
