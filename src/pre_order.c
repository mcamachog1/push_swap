#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"


void pre_order(t_stack *a, t_stack *b)
{
	int sum;
	int n;
	int i;

	n = a->top;
	sum = 0;
	i = 0;
	while (i < n)
	{
		sum += a->array[i];
		i++;			
	}
	while (i >= 0)
	{
		if (a->array[a->top - 1] <= sum / n)
			op_push("pb", a, b);
		else
			op_rotate("ra", a, NULL);
		i--;
	}
}