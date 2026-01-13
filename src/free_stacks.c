#include <stdlib.h>
#include "push_swap.h"

static void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

