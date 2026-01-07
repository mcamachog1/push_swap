#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}
