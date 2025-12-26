#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	//test swap
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 2 elements
	push_stack(a, 5);
	push_stack(a, 3);
	printf("inicio swap con dos elementos\n");
	print_stack(a, b);
	op_swap("sa", a, b);
	printf("swap\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	//test swap
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 1 elements
	push_stack(a, 3);
	printf("inicio swap con un elemento\n");
	print_stack(a, b);
	op_swap("sa", a, b);
	printf("swap\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	//test swap
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 0 elements
	printf("inicio swap con cero elementos\n");
	print_stack(a, b);
	op_swap("sa", a, b);
	printf("swap\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	return (0);
}
