#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "stacks.h"

void	op_swap(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa", op, 2))
		if (swap(a) == 0)
			write(1, "sa\n", 3);
	if (!ft_strncmp("sb", op, 2))
		if (swap(b) == 0)
			write(1, "sb\n", 3);
	if (!ft_strncmp("ss", op, 2))
		if (swap(a) == 0 && swap(b) == 0)
			write(1, "ss\n", 3);
}
