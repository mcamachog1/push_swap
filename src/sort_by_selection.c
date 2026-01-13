#include "push_swap.h"

void	sort_by_selection(t_stack *a, t_stack *b)
{
	if (a->top > 3)
	{
		while (a->top > 3)
		{
			min_first(a);
			op_push("pb", a, b);
		}
		order_3(a);
		while (b->top > 0)
			op_push("pa", a, b);
		return ;
	}
	if (a->top == 3)
		order_3(a);	
	if (a->top == 2)
		if (a->array[1] > a->array[0])
			op_swap("sa", a, NULL);
}
