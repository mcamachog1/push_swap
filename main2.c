#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc <  2)
	{
		printf("Arguments error\n");
		return (1);
	}
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	if (!a || !b)
		return (0);
	//printf("Elementos:[%d]\n", argc - 1);
	i = argc - 1;
	while (i > 0)
	{
		push_stack(a, atoi(argv[i]));
		i--;
	}
	//print_stack(a, b);
	while (a->top > 0)
	{
		while (b->top > 0 && b->array[b->top - 1] > a->array[a->top - 1])
		{
			op_rotate("ra", a, b);
			op_push("pa", a, b);
			op_rotate("rra", a, b);
		}
		op_push("pb", a, b);
	}
	while (b->top > 0)
		op_push("pa", a, b);
	//printf("Sorted:\n");
	//print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}
