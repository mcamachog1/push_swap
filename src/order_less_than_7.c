#include "push_swap.h"

void	order_less_than_7(t_stack *a, t_stack *b)
{
	if (a->top == 2)
		if (a->array[0] < a->array[1])
			op_swap("sa", a, NULL);
	if (a->top == 3)
		order_3(a);
	if (a->top == 4)
		order_4(a, b);
	if (a->top == 5)
		order_5(a, b);
	if (a->top == 6)
		order_6(a, b);				
	free_stack(a);
	free_stack(b);
}
