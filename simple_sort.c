/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simple_sort.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/31 02:24:04 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 02:24:04 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	find_min(t_node *stack_a)
{
	t_node	*tmp;
	int		min;
	int		i;
	int		ret;

	ret = 1;
	i = 1;
	tmp = stack_a;
	min = tmp->data;
	while (tmp->next)
	{
		i++;
		tmp = tmp->next;
		if (tmp->data < min)
		{
			min = tmp->data;
			ret = i;
		}
	}
	return (ret);
}

static void	sort_3(t_stack *s)
{
	if (is_list_sorted(s->stack_a) == 1)
		return ;
	if (find_min(s->stack_a) == 1)
	{
		rra(s);
		sa(s);
	}
	else if (find_min(s->stack_a) == 2)
	{
		if (s->stack_a->data < s->stack_a->next->next->data)
			sa(s);
		else
			ra(s);
	}
	else
	{
		if (s->stack_a->data < s->stack_a->next->data)
			rra(s);
		else
		{
			ra(s);
			sa(s);
		}
	}
}

static void	sort_4(t_stack *s)
{
	if (find_min(s->stack_a) == 2)
		ra(s);
	else if (find_min(s->stack_a) == 3)
	{
		rra(s);
		rra(s);
	}
	else if (find_min(s->stack_a) == 4)
		rra(s);
	pb(s);
	sort_3(s);
	pa(s);
}

static void	sort_5(t_stack *s)
{
	if (find_min(s->stack_a) == 2)
		ra(s);
	else if (find_min(s->stack_a) == 3)
	{
		ra(s);
		ra(s);
	}
	else if (find_min(s->stack_a) == 4)
	{
		rra(s);
		rra(s);
	}
	else if (find_min(s->stack_a) == 5)
		rra(s);
	pb(s);
	sort_4(s);
	pa(s);
}

void	simple_sort(t_stack *s, size_t stack_size)
{
	if (is_list_sorted(s->stack_a))
		return ;
	if (stack_size == 2
		&& s->stack_a->data > s->stack_a->next->data)
		sa(s);
	else if (stack_size == 3)
		sort_3(s);
	else if (stack_size == 4)
		sort_4(s);
	else if (stack_size == 5)
		sort_5(s);
}
