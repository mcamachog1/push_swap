#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

int	rotate(t_stack *s)
{
	int	temp;
	int	i;

	if (s->top <= 1)
		return (1);
	temp = s->array[s->top - 1];
	i = s->top - 1;
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = temp;
	return (0);
}