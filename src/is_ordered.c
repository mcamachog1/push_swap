#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

int	is_ordered(t_stack *s)
{
	int	i;

	if (s->top <= 1)
		return (1);
	i = s->top - 1;
	while (i > 0)
	{
		if (s->array[i] > s->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
