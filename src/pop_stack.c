#include "push_swap.h"

int	pop_stack(t_stack *s, int *number)
{
	if (s->top <= 0)
		return (1);
	s->top--;
	*number = s->array[s->top];
	return (0);
}