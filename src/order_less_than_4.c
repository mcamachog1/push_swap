#include "push_swap.h"

int	order_less_than_4(t_stack *a)
{
	if (a->top == 1)
		return (0);
	if (a->top == 2)
	{
		if (a->array[0] < a->array[1])
			op_swap("sa", a, NULL);
		return (0);
	}
	if (a->top == 3)
	{
		order_3(a);
		return (0);
	}
	return (1);
}
