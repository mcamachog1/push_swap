#include "push_swap.h"

void	optimize_moves(t_moves *moves)
{
	int	min_a;
	int	min_b;
	int	cost;

	min_a = ft_min(moves->ra_moves, moves->rra_moves);
	min_b = ft_min(moves->rb_moves, moves->rrb_moves);
	if (moves->ra_moves == min_a && moves->rb_moves == min_b)
	{
		moves->rr_moves = ft_min(moves->ra_moves, moves->rb_moves);
		moves->ra_moves -= moves->rr_moves;
		moves->rb_moves -= moves->rr_moves;
	}
	else if (moves->rra_moves == min_a && moves->rrb_moves == min_b)
	{
		moves->rrr_moves = ft_min(moves->rra_moves, moves->rrb_moves);
		moves->rra_moves -= moves->rrr_moves;
		moves->rrb_moves -= moves->rrr_moves;
	}
	cost = ft_min(moves->ra_moves, moves->rra_moves) + ft_min(moves->rb_moves, moves->rrb_moves) + moves->rr_moves + moves->rrr_moves;
	moves->total_moves = cost;
}