#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_cost.h"

typedef struct moves
{
	int	ra_moves;
	int	rb_moves;
	int	rra_moves;
	int	rrb_moves;
	int rr_moves;
	int rrr_moves;
	int	total_moves;
	int number;
}	t_moves;

t_moves *new_moves(int number)
{
	t_moves *moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		return (NULL);
	moves->ra_moves = MAX_COST;
	moves->rb_moves = MAX_COST;
	moves->rra_moves = MAX_COST;
	moves->rrb_moves = MAX_COST;
	moves->rr_moves = MAX_COST;
	moves->rrr_moves = MAX_COST;
	moves->total_moves = MAX_COST;
	moves->number = number;
	return (moves);
}

void	put_min_first(t_stack *a)
{
	int i;
	int j;

	i = 0;
	while (i < a->top)
	{
		if (a->array[a->top - 1 - i] > a->array[0])
			i++;
		else
			break ;
	}
	if (i <= a->top / 2)
	{
		j = 0;
		while (j++ < i)
			op_rotate("ra", a, NULL);
	}
	else
	{
		j = 0;
		while (j++ < a->top - i)
			op_rotate("rra", a, NULL);
	}
}

void calculate_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int		target;

	target = get_target(b, moves->number);
	moves->ra_moves = cost_ra(a, moves->number);
	moves->rra_moves = cost_rra(a, moves->number);
	moves->rb_moves = cost_rb(b, target);
	moves->rrb_moves = cost_rrb(b, target);
	moves->total_moves = ft_min(moves->ra_moves, moves->rra_moves) + ft_min(moves->rb_moves, moves->rrb_moves);	
}

void print_moves(t_moves *moves)
{
	printf("Moves for number %d:\n", moves->number);
	printf("Number: %d\n", moves->number);
	printf("RA moves: %d\n", moves->ra_moves);
	printf("RRA moves: %d\n", moves->rra_moves);
	printf("RB moves: %d\n", moves->rb_moves);
	printf("RRB moves: %d\n", moves->rrb_moves);
	printf("Total moves: %d\n", moves->total_moves);
}

void exec_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int		i;

	i = 0;
	if (moves->ra_moves <= moves->rra_moves)
	{
		while (i < moves->ra_moves)
		{
			op_rotate("ra", a, NULL);
			i++;
		}
	}
	else
	{
		while (i < moves->rra_moves)
		{
			op_rotate("rra", a, NULL);
			i++;
		}
	}
	i = 0;
	if (moves->rb_moves <= moves->rrb_moves)
	{
		while (i < moves->rb_moves)
		{
			op_rotate("rb", NULL, b);
			i++;
		}
	}
	else
	{
		while (i < moves->rrb_moves)
		{
			op_rotate("rrb", NULL, b);
			i++;
		}
	}	
}

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
			moves->number = a->array[i];
			calculate_moves(moves, a, b);
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
	while (b->top > 0)
		op_push("pa", a, b);
	put_min_first(a);
	//print_stack(a, b);
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);

    return (0);
}
