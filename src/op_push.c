#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

void	op_push(char *op, t_stack *a, t_stack *b)
{
	int	n;

	if (!ft_strncmp("pa", op, 2))
	{
		if (pop_stack(b, &n) == 0)
			if (push_stack(a, n) == 0)
				write(1, "pa\n", 3);
	}
	if (!ft_strncmp("pb", op, 2))
	{
		if (pop_stack(a, &n) == 0)
			if (push_stack(b, n) == 0)
				write(1, "pb\n", 3);
	}
}
