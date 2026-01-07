
#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

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
		return (NULL);
	return (s);
}