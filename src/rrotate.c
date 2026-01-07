#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

int	rrotate(t_stack *s)
{
	int	temp;
	int	i;

	if (s->top <= 1)
		return (1);
	temp = s->array[0];
	i = 0;
	while (i < s->top - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->top - 1] = temp;
	return (0);
}
