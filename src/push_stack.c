#include "push_swap.h"

int	push_stack(t_stack *s, int number)
{
	if (s->top >= s->capacity)
		return (1);
	s->array[s->top] = number;
	s->top++;
	return (0);
}