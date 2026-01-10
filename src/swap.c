#include "push_swap.h"

int	swap(t_stack *s)
{
	int	temp_1;
	int	temp_2;

	if (s->top <= 1)
		return (1);
	pop_stack(s, &temp_1);
	pop_stack(s, &temp_2);
	push_stack(s, temp_1);
	push_stack(s, temp_2);
	return (0);
}