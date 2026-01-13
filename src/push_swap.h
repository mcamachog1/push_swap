#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_COST
#  define MAX_COST 1000
# endif

# include <stddef.h>

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
void	free_stack(t_stack *s);
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
int		ft_max(int a, int b);
int		ft_min(int a, int b);
t_moves	*get_best_moves(t_stack *a, t_stack *b, t_moves *min_moves);
int		*get_params(char **argv, int *size);
int		input_error(int argc, char **argv);
void	load_stack_a(t_stack *a, int *numbers, int size);

#endif