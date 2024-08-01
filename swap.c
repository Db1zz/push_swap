/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:38:56 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 20:53:39 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	swap_stack(t_node **first, t_node **second)
{
	if (!first || !second)
		return ;
	swap_node(first, second);
	(*second)->next = (*first)->last;
	(*first)->last = NULL;
	(*first)->next = *second;
	(*second)->last = *first;
}
