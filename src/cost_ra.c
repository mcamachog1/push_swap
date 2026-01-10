#include "push_swap.h"

int	cost_ra(t_stack *a, int n)
{
	return (a->top - get_index(a, n) - 1);
}