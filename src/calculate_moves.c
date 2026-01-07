#include "push_swap.h"

void calculate_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int		target;

	target = get_target(b, moves->number);
	moves->ra_moves = cost_ra(a, moves->number);
	moves->rra_moves = cost_rra(a, moves->number);
	moves->rb_moves = cost_rb(b, target);
	moves->rrb_moves = cost_rrb(b, target);
	moves->total_moves = ft_min(moves->ra_moves, moves->rra_moves) + ft_min(moves->rb_moves, moves->rrb_moves);	
}