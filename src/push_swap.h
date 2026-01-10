
#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# ifndef MAX_COST
#  define MAX_COST 1000
# endif

#include <stddef.h>

typedef struct stack
{
	int	*array;
	int	top;
	int	capacity;
}	t_stack;

typedef struct moves
{
	int	ra_moves;
	int	rb_moves;
	int	rra_moves;
	int	rrb_moves;
	int rr_moves;
	int rrr_moves;
	int	total_moves;
	int number;
}	t_moves;

void exec_moves(t_moves *moves, t_stack *a, t_stack *b);

int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	get_index(t_stack *s, int number);
int	get_target(t_stack *s, int number);
void calculate_moves(t_moves *moves, t_stack *a, t_stack *b);
int	cost_ra(t_stack *a, int n);
int	cost_rra(t_stack *a, int n);
int	cost_rb(t_stack *b, int n);
int	cost_rrb(t_stack *b, int n);
void order_3(t_stack *s);
int	input_error(int argc, char **argv);
void	print_stack(t_stack *a, t_stack *b);
int	is_ordered(t_stack *s);
t_stack	*new_stack(int size);
t_moves *new_moves(int number);
void	optimize_moves(t_moves *moves);
int	push_stack(t_stack *s, int number);
int	pop_stack(t_stack *s, int *number);
void	free_stack(t_stack *s);
int	rrotate(t_stack *s);
int	rotate(t_stack *s);
int	swap(t_stack *s);
void	op_swap(char *op, t_stack *a, t_stack *b);
void	op_push(char *op, t_stack *a, t_stack *b);
void	op_rotate(char *op, t_stack *a, t_stack *b);
void	put_min_first(t_stack *a);
#endif
