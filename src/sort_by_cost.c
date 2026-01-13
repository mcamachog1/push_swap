#include <stdlib.h>
#include "push_swap.h"

int	sort_by_cost(t_stack *a, t_stack *b)
{
	int		i;
	t_moves	*min_moves;

	op_push("pb", a, b);
	op_push("pb", a, b);
	while (a->top > 0)
	{
		i = a->top - 1;
		min_moves = new_moves(a->array[i]);
		if (!min_moves)
			return (0);
		min_moves = get_best_moves(a, b, min_moves);
		exec_moves(min_moves, a, b);
		op_push("pb", a, b);
		free(min_moves);
	}
	return (1);
}
