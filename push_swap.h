/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 20:52:47 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

#include "./ft_printf/libft/libft.h"
#include "./ft_printf/include/ft_printf.h"

typedef struct t_node
{
	struct t_node	*next;
	struct t_node	*last;
	int		data;
}	t_node;

t_node	*alloc_node(t_node *next, t_node *last, int data);
void	swap_node(t_node **a, t_node **b);
void	swap_stack(t_node **first, t_node **second);
void	rotate_stack(t_node **stack_first, t_node **stack_last);
void	push_stack(t_node **stack_a, t_node **stack_b);

#endif // PUSH_SWAP_H