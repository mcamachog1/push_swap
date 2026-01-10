#include "push_swap.h"

void	put_min_first(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->top)
	{
		if (a->array[a->top - 1 - i] > a->array[0])
			i++;
		else
			break ;
	}
	if (i <= a->top / 2)
	{
		j = 0;
		while (j++ < i)
			op_rotate("ra", a, NULL);
	}
	else
	{
		j = 0;
		while (j++ < a->top - i)
			op_rotate("rra", a, NULL);
	}
}