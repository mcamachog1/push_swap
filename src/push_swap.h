/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:29:05 by macamach          #+#    #+#             */
/*   Updated: 2026/01/21 13:55:47 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_COST
#  define MAX_COST 2000
# endif

# include <stdlib.h>
# include <unistd.h>
# include <stddef.h>
# include "libft.h"

typedef struct stack
{
	int			*array;
	int			top;
	int			capacity;
}	t_stack;

typedef struct moves
{
	int			ra_moves;
	int			rb_moves;
	int			rra_moves;
	int			rrb_moves;
	int			rr_moves;
	int			rrr_moves;
	int			total_moves;
	int			number;
}	t_moves;

/* --- Memory management and stacks --- */
void	free_stacks(t_stack *a, t_stack *b, int error);
void	free_string_pointers(char **pointers, int error);
t_moves	*new_moves(int number);
t_stack	*new_stack(int size);
int		pop_stack(t_stack *s, int *number);
int		push_stack(t_stack *s, int number);

/* --- Operations --- */
void	op_push(char *op, t_stack *a, t_stack *b);
void	op_rotate(char *op, t_stack *a, t_stack *b);
void	op_swap(char *op, t_stack *a, t_stack *b);
int		rotate(t_stack *s);
int		rrotate(t_stack *s);
int		swap(t_stack *s);

/* --- Algorithm logic and costs --- */
void	calculate_moves(t_moves *moves, t_stack *a, t_stack *b);
int		cost_ra(t_stack *a, int n);
int		cost_rb(t_stack *b, int n);
int		cost_rra(t_stack *a, int n);
int		cost_rrb(t_stack *b, int n);
void	exec_moves(t_moves *moves, t_stack *a, t_stack *b);
int		get_index(t_stack *s, int number);
int		get_target(t_stack *s, int number);
int		is_ordered(t_stack *s);
void	min_first(t_stack *a);
void	optimize_moves(t_moves *moves);
void	order_3(t_stack *s);
int		sort_by_cost(t_stack *a, t_stack *b);
void	sort_by_selection(t_stack *a, t_stack *b);

/* --- Utilities and validation --- */
int		ft_atoi_plus(const char *nptr, int *integer);
int		ft_max(int a, int b);
int		ft_min(int a, int b);
t_moves	*get_best_moves(t_stack *a, t_stack *b, t_moves *min_moves);
int		*get_params(int argc, char **argv, int *size);
int		input_error(int argc, char **argv);
int		is_duplicated(int *array, int n, int size);
void	load_stack_a(t_stack *a, int *numbers, int size);

#endif
