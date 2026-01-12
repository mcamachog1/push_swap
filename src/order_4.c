#include "push_swap.h"
//#include <stdio.h>

//static void	print_stack(t_stack *a, t_stack *b);

void	order_4(t_stack *a, t_stack *b)
{
	min_first(a);
	op_push("pb", a, b);
	order_3(a);
	op_push("pa", a, b);
}

// static void	print_stack(t_stack *a, t_stack *b)
// {
// 	int	i;
// 	int	j;

// 	i = a->top - 1;
// 	j = b->top - 1;
// 	printf("\n");
// 	while (i >= 0 || j >= 0)
// 	{
// 		if (i >= 0)
// 			printf("%i  ", a->array[i]);
// 		else
// 			printf("   ");
// 		if (j >= 0)
// 			printf("%i  ", b->array[j]);
// 		else
// 			printf("   ");
// 		printf("\n");
// 		i--;
// 		j--;
// 	}
// 	printf("\n");
// 	printf("-  -\n");
// 	printf("a  b\n");
// }