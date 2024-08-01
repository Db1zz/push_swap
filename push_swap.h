/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/01 17:47:51 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/libft.h"

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct t_node
{
	t_node	*next;
	t_node	*last;
	int		data;
}	t_node;

#endif // PUSH_SWAP_H