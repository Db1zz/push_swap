/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/04 11:42:03 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 04:29:52 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_node	*alloc_list(const int **num_set)
{
	t_node	*result;
	t_node	*tail;
	size_t	i;

	i = 0;
	result = alloc_node(NULL, NULL, *num_set[i++]);
	tail = result;
	if (!result)
		return (NULL);
	while (num_set[i])
	{
		tail->next = alloc_node(NULL, tail, *num_set[i++]);
		if (!tail->next)
		{
			ft_printf("Error\n");
			free_list(result);
			return (NULL);
		}
		tail = tail->next;
	}
	return (result);
}

void	free_list(t_node *list_head)
{
	t_node	*next;

	if (!list_head)
		return ;
	while (list_head)
	{
		next = list_head->next;
		free(list_head);
		list_head = next;
	}
}

t_stack	*init_stack(char **argv)
{
	t_stack	*result;
	int		**num_set;

	num_set = parse_nums(argv);
	if (num_set == NULL)
		return (NULL);
	result = (t_stack *)ft_calloc(1, sizeof(t_stack));
	if (!result)
		return (NULL);
	result->stack_a = alloc_list((const int **)num_set);
	if (!result->stack_a)
	{
		ft_printf("Error\n");
		free(result);
		return (NULL);
	}
	free_int_2d_matrix(num_set);
	result->stack_b = NULL;
	return (result);
}

void	free_stack(t_stack **stack)
{
	if (stack && *stack)
	{
		free_list((*stack)->stack_a);
		free_list((*stack)->stack_b);
		free(*stack);
		*stack = NULL;
	}
}

bool	is_list_sorted(t_node *list)
{
	while (list->next)
	{
		if (list->data > list->next->data)
			return (false);
		list = list->next;
	}
	return (true);
}
