#include "push_swap.h"
//#include <stdio.h>

//static void	print_stack(t_stack *a, t_stack *b);

void	order_6(t_stack *a, t_stack *b)
{
	min_first(a);
	op_push("pb", a, b);
	min_first(a);
	op_push("pb", a, b);  
	min_first(a);
	op_push("pb", a, b);       
	order_3(a);
	op_push("pa", a, b);
    op_push("pa", a, b);
    op_push("pa", a, b);    
}