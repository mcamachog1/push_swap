#include <stdlib.h>
#include "push_swap.h"

t_stack	*new_stack(int size)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->top = 0;
	s->capacity = size;
	s->array = malloc(size * sizeof(int));
	if (!s->array)
		return (0);
	return (s);
}
