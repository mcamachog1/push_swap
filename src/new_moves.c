#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"


t_moves *new_moves(int number)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		return (NULL);
	moves->ra_moves = MAX_COST;
	moves->rb_moves = MAX_COST;
	moves->rra_moves = MAX_COST;
	moves->rrb_moves = MAX_COST;
	moves->rr_moves = 0;
	moves->rrr_moves = 0;
	moves->total_moves = MAX_COST;
	moves->number = number;
	return (moves);
}