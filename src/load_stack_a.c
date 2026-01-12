#include "push_swap.h"

void	load_stack_a(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push_stack(a, numbers[size - 1 - i]);
		i++;
	}
}
