#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"

void exec_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int		ma;
	int		mb;

	ma = ft_min(moves->ra_moves, moves->rra_moves);
	mb = ft_min(moves->rb_moves, moves->rrb_moves);
	while (moves->rr_moves > 0)
	{
		op_rotate("rr", a, b);
		moves->rr_moves--;
	}
	while (moves->rrr_moves > 0)
	{
		op_rotate("rrr", a, b);
		moves->rrr_moves--;
	}
	while (ma>0)
	{
		if (moves->ra_moves == ma)
		{
			op_rotate("ra", a, NULL);
			moves->ra_moves--;
		}
		else
		{
			op_rotate("rra", a, NULL);
			moves->rra_moves--;
		}
		ma--;
	}
	while (mb>0)
	{
		if (moves->rb_moves == mb)
		{
			op_rotate("rb", NULL, b);
			moves->rb_moves--;	
		}
		else
		{
			op_rotate("rrb", NULL, b);
			moves->rrb_moves--;
		}
		mb--;	
	}
}
