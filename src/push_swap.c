#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"

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
	if (a->top == 1)
	{
		return (0);
	}
    	if (a->top == 2)
	{
		if(a->array[0] < a->array[1])
			op_swap("sa", a, NULL);
		return (0); 
	}
	if (a->top == 3)
	{
		order_3(a);
		return (0);
	}
	//print_stack(a, b);
	//pre_order(a, b);
	//print_stack(a, b);
	while (b->top > 0)
		op_push("pa", a, b);
	//print_stack(a, b);	
	op_push("pb", a, b);
	op_push("pb", a, b);
	t_moves *moves;
	t_moves *min_moves;
	while (a->top > 0)
	{
		i = a->top - 1;
		min_moves = new_moves(a->array[i]);
		if (!min_moves)
			return (0);
		while (i >= 0)
		{
			moves = new_moves(a->array[i]);
			if (!moves)
				return (0);
			//moves->number = a->array[i];
			calculate_moves(moves, a, b);
			optimize_moves(moves);
			if (moves->total_moves < min_moves->total_moves)
			{
				free(min_moves);
				min_moves = moves;
				i--;
				continue;
			}	
			free(moves);
			i--;
		}
		exec_moves(min_moves, a, b);
		op_push("pb", a, b);
		free(min_moves);
	}
	//order_3(a);
	while (b->top > 0)
	{
		//while (b->array[b->top - 1] > a->array[a->top - 1])
		//	op_rotate("ra", a, NULL);
		op_push("pa", a, b);
	}
	put_min_first(a);
	//print_stack(a, b);
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);

    return (0);
}
