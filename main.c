#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
	char	**split;
    int i;


	if (input_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	} 
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		i = 0;
		while (split[i] != NULL)
			i++;
		a = new_stack(i);
		b = new_stack(i);
		if (!a || !b)
			return (0);
		while (i > 0)
		{
			push_stack(a, atoi(split[i - 1]));
			i--;
		}
		free(split);	
	}
	else
	{
		a = new_stack(argc - 1);
		b = new_stack(argc - 1);
		if (!a || !b)
			return (0);
		i = argc - 1;
		while (i > 0)
		{
			push_stack(a, atoi(argv[i]));
			i--;
		}
	}
    //print_stack(a, b);
    while (a->top > 0)
    {
        //print_stack(a, b);
        if (a->top > 1 && a->array[a->top - 1] > a->array[a->top - 2])
            op_swap("sa", a, b);
        if (is_ordered(a) && b->top <= 0)
        {
            //printf("Sorted:\n");
            break;
        }
        else if (is_ordered (a) && a->array[a->top - 1] >= b->array[b->top - 1] )
        {
            //printf("Sorted:\n");
            break;
        }
             
        //&& b->top > 0 && a->array[a->top - 1] >= b->array[b->top - 1]       
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
    //print_stack(a, b);
    // printf("Sorted:\n");
 
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    return (0);
}
