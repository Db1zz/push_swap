/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gonische <gonische@student.42wolfsburg.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/01 17:43:55 by gonische          #+#    #+#             */
/*   Updated: 2024/08/31 03:45:12 by gonische         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdlib.h>
# include <stdbool.h>
# include <stdio.h>
# include <limits.h>
# include <bits/stdint-intn.h> 
# include "./libft/libft.h"

/*
	Preprocessor definitions
*/
# ifndef SORT_THRESHOLD
#  define SORT_THRESHOLD 45
# endif // SORT_THRESHOLD

/*
	Type definitions
*/
typedef struct t_node
{
	struct t_node	*next;
	struct t_node	*last;
	int				data;
}	t_node;

typedef struct t_stack
{
	t_node	*stack_a;
	t_node	*stack_b;
}	t_stack;

typedef struct t_pivot
{
	t_node	*pivot;
	int		smaller_equals;
	int		bigger_equals;
}	t_pivot;

/*
	Chunk functions
*/
void	split_chunk(t_node **chunk_list, t_node **chunk, t_stack *s,
			t_pivot *p);
void	create_chunks(t_node **start, t_node **chunk, size_t lchunk_s,
			size_t rchunk_s);
size_t	get_amount_of_chunks(t_node *chunk);
void	next_chunk(t_node **chunk_list, t_node **chunk);
bool	is_chunk_sorted(const t_node *chunk_start, size_t chunk_size);
bool	are_chunks_sorted(t_node *chunk_list, t_node *chunk, t_node *s);

/*
	Pivot functions 
*/
t_pivot	*get_pivot(t_node *stack_start, size_t size);
bool	choose_this_pivot(t_pivot *p, size_t chunk_size);

/*
	List functions
*/
t_node	*alloc_node(t_node *next, t_node *last, int data);
void	free_node(t_node **node);
int		get_path_to_value_in_list(t_node *list, int value);
t_node	*get_last_node(t_node *list);
t_node	*get_node_at_index(t_node *list, size_t index);
t_node	*get_biggest_val_in_lst(t_node *list);
t_node	*get_smallest_val_in_lst(t_node *list);
size_t	get_list_size(t_node *list);

/*
	Sort functions
*/
void	sort(t_stack *s);
void	sort_chunk(t_stack *s, size_t chunk_size);
void	simple_sort(t_stack *s, size_t stack_size);

/*
	Stack Instructions
*/
bool	swap_stack(t_node **stack_frist);
bool	rotate_stack(t_node **stack_first);
bool	rev_rotate_stack(t_node **stack_first);
bool	push_stack(t_node **push_from, t_node **push_to);
void	sa(t_stack *s);
void	sb(t_stack *s);
void	ra(t_stack *s);
void	rb(t_stack *s);
void	rra(t_stack *s);
void	rrb(t_stack *s);
void	pa(t_stack *s);
void	pb(t_stack *s);
void	rrr(t_stack *s);
void	push_a(t_stack *stack);
void	rotate_stack_a(t_stack *s, int64_t rotations);
void	rotate_stack_b(t_stack *s, int64_t rotations);

/*
	Stack utils
*/
t_stack	*init_stack(char **argv);
t_node	*alloc_list(const int **num_set);
void	free_stack(t_stack **stack);
void	free_list(t_node *list_head);
bool	is_list_sorted(t_node *list);

/*
	Utils
*/
int64_t	ft_atoi_int64(const char *str);
void	free_int_2d_matrix(int **matrix);
int		**parse_nums(char **argv);

#endif // PUSH_SWAP_H