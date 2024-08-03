/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 20:15:56 by gonische          #+#    #+#             */
/*   Updated: 2024/08/02 18:47:03 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TEST_H
# define TEST_H

#include <stddef.h>
#include <stdlib.h>
#include "../push_swap.h"

t_node	*alloc_stack(size_t stack_size);
void	print_stack(t_node *stack);
void	print_backwards(t_node *stack_last);
void	free_stack(t_node *stack_top);
t_node	*get_last_node(t_node *stack);

#endif // TEST_H