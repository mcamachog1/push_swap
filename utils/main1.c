#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc <  1)
	{
		printf("Arguments error\n");
		return (0);
	}
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	if (!a || !b)
		return (0);
	printf("Elementos:[%d]\n", argc - 1);
	i = argc - 1;
	while (i > 0)
	{
		push_stack(a, atoi(argv[i]));
		i--;
	}
	while (a->top > 0)
	{
		while (b->top > 0 && b->array[b->top - 1] < a->array[a->top - 1])
		{
			op_rotate("ra", a, b);
			op_push("pb", a, b);
			op_rotate("rra", a, b);
			op_push("pa", a, b);
			op_push("pa", a, b);
		}
		op_push("pb", a, b);
	}
	printf("inicio\n");
	print_stack(a, b);
	printf("sa\n");
	op_swap("sa", a, b);
	print_stack(a, b);
	printf("pb pb pb\n");
	op_push("pb", a, b);
	op_push("pb", a, b);
	op_push("pb", a, b);
	print_stack(a, b);
	printf("rr\n");
	op_rotate("rr", a, b);
	print_stack(a, b);
	printf("rrr\n");
	op_rotate("rrr", a, b);
	print_stack(a, b);
	printf("sa\n");
	op_swap("sa", a, b);
	print_stack(a, b);
	printf("pa pa pa\n");
	op_push("pa", a, b);
	op_push("pa", a, b);
	op_push("pa", a, b);
	print_stack(a, b);

	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}
