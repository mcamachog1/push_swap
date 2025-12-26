#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int	n;
	//test pop
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 0 elements
	printf("inicio pop con 0 elementos\n");
	print_stack(a, b);
	if (pop_stack(a, &n) == 0)
		printf("pop_stack doesn't returned 0\n");
	else
		printf("pop_stack return error (1) as expected\n");	
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	//test pop
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 1 element
	printf("inicio pop con 1 elementos\n");
	push_stack(a, 3);
	print_stack(a, b);
	if (pop_stack(a, &n) == 0)
		printf("pop_stack return number %i\n", n);
	else
		printf("pop_stack return error (1) as expected\n");	
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	
	//test pop
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 2 elements
	printf("inicio pop con 2 elementos\n");
	push_stack(a, 3);
	push_stack(a, 1);
	print_stack(a, b);
	if (pop_stack(a, &n) == 0)
		printf("pop_stack return number %i\n", n);
	else
		printf("pop_stack return error (1) as expected\n");	
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);	

	return (0);
}
