#include "push_swap.h"

void	order_3(t_stack *s)
{
	if (s->top != 3)
		return ;
	if (s->array[0] > s->array[2] && s->array[1] > s->array[0])
	{
		op_rotate("rra", s, NULL);
		op_swap("sa", s, NULL);
	}
	if (s->array[2] > s->array[1] && s->array[0] > s->array[2])
		op_swap("sa", s, NULL);
	if (s->array[1] > s->array[2] && s->array[2] > s->array[0])
		op_rotate("rra", s, NULL);
	if (s->array[2] > s->array[0] && s->array[0] > s->array[1])
		op_rotate("ra", s, NULL);
	if (s->array[2] > s->array[1] && s->array[1] > s->array[0])
	{
		op_rotate("ra", s, NULL);
		op_swap("sa", s, NULL);
	}
}
