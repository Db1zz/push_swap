/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/03 08:29:08 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./ft_printf/libft/libft.h"
#include "./ft_printf/include/ft_printf.h"

// Typedefs

typedef struct t_node
{
	struct t_node	*next;
	struct t_node	*last;
	int				data;
}	t_node;

typedef void (*function_ptr)(t_node **, t_node **);

t_node	*alloc_node(t_node *next, t_node *last, int data);
void	swap_node(t_node **a, t_node **b);
void	swap_stack(t_node **stack_frist, t_node **stack_second);
void	rotate_stack(t_node **stack_first, t_node **stack_last);
void	push_stack(t_node **push_from, t_node **push_to);

// void	swap_stack_a(t_node **stack);
// void	swap_stack_b(t_node **stack);
void	rotate_stack_b(t_node **stack_first, t_node **stack_last);
void	rotate_stack_b(t_node **stack_first, t_node **stack_last);
void	push_stack_a(t_node **push_from, t_node **push_to);
void	push_stack_b(t_node **push_from, t_node **push_to);

#endif // PUSH_SWAP_H