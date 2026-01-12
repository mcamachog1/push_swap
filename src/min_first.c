#include "push_swap.h"

void	min_first(t_stack *a)
{
	int	min_idx;
	int	min_val;
	int	i;

	if (a->top < 0)
		return ;
	min_idx = 0;
	min_val = a->array[0];
	i = 1;
	while (i < a->top)
	{
		if (a->array[i] < min_val)
		{
			min_val = a->array[i];
			min_idx = i;
		}
		i++;
	}
	if (min_idx >= a->top / 2)
		while (a->array[a->top - 1] != min_val)
			op_rotate("ra", a, NULL);
	else
		while (a->array[a->top - 1] != min_val)
			op_rotate("rra", a, NULL);
}