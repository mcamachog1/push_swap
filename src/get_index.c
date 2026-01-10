#include "push_swap.h"

int	get_index(t_stack *s, int number)
{
	int	i;

	i = 0;
	while(s->array[i] != number && i < s->top)
		i++;
	if (i == s->top)
		return (-1);
	else
		return (i);
}