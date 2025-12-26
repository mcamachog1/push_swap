#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	main(void)
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	//test push
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 0 elements
	printf("inicio push con 0 elementos\n");
	print_stack(a, b);
	push_stack(a, 3);
	print_stack(a, b);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	//test push
	a = new_stack(2);
	b = new_stack(2);
	if (!a || !b)
		return (0);
	// Initialize stacks 1 element
	printf("inicio push con 1 elemento\n");
	push_stack(a, 3);
	print_stack(a, b);
	push_stack(a, 1);
	print_stack(a, b);	
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);

	return (0);
}
