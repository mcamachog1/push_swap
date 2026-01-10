#include <stdlib.h>
#include "push_swap.h"

void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}
