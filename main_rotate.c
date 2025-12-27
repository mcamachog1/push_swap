#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;

	a = new_stack(3);
	b = new_stack(3);
	if (!a || !b)
		return (1);
	// Initialize stacks 3 elements
	printf("inicio rotate con 3 elementos\n");
	push_stack(a, 3);
	push_stack(a, 2);
	push_stack(a, 1);
	print_stack(a, b);
	op_rotate("ra", a, b);
	printf("despues ra\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	// Initialize stacks 2 elements
	a = new_stack(3);
	b = new_stack(3);
	if (!a || !b)
		return (1);	
	printf("inicio rotate con 2 elementos\n");
	push_stack(a, 2);
	push_stack(a, 1);
	print_stack(a, b);
	op_rotate("ra", a, b);
	printf("despues ra\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	// Initialize stacks 1 element
	a = new_stack(3);
	b = new_stack(3);
	if (!a || !b)
		return (1);	
	printf("inicio rotate con 1 elemento\n");
	push_stack(a, 1);
	print_stack(a, b);
	op_rotate("ra", a, b);
	printf("despues ra\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);	

	// Initialize stacks 0 elements
	a = new_stack(3);
	b = new_stack(3);
	if (!a || !b)
		return (1);	
	printf("inicio rotate con 0 elementos\n");
	print_stack(a, b);
	op_rotate("ra", a, b);
	printf("despues ra\n");
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);	

	return (0);
}
