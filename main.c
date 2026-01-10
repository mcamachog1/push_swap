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
	moves->rr_moves = 0;
	moves->rrr_moves = 0;
	moves->total_moves = MAX_COST;
	moves->number = number;
	return (moves);
}

void pre_order(t_stack *a, t_stack *b)
{
	int sum;
	int n;
	int i;

	n = a->top;
	sum = 0;
	i = 0;
	while (i < n)
	{
		sum += a->array[i];
		i++;			
	}
	while (i >= 0)
	{
		if (a->array[a->top - 1] <= sum / n)
			op_push("pb", a, b);
		else
			op_rotate("ra", a, NULL);
		i--;
	}
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

void	optimize_moves(t_moves *moves)
{
	int	min_a;
	int	min_b;
	int	cost;

	min_a = ft_min(moves->ra_moves, moves->rra_moves);
	min_b = ft_min(moves->rb_moves, moves->rrb_moves);
	if (moves->ra_moves == min_a && moves->rb_moves == min_b)
	{
		moves->rr_moves = ft_min(moves->ra_moves, moves->rb_moves);
		moves->ra_moves -= moves->rr_moves;
		moves->rb_moves -= moves->rr_moves;
	}
	else if (moves->rra_moves == min_a && moves->rrb_moves == min_b)
	{
		moves->rrr_moves = ft_min(moves->rra_moves, moves->rrb_moves);
		moves->rra_moves -= moves->rrr_moves;
		moves->rrb_moves -= moves->rrr_moves;
	}
	cost = ft_min(moves->ra_moves, moves->rra_moves) + ft_min(moves->rb_moves, moves->rrb_moves) + moves->rr_moves + moves->rrr_moves;
	moves->total_moves = cost;
}

void print_moves(t_moves *moves)
{
	printf("Moves for number %d:\n", moves->number);
	printf("Number: %d\n", moves->number);
	printf("ra moves: %d\n", moves->ra_moves);
	printf("rra moves: %d\n", moves->rra_moves);
	printf("rb moves: %d\n", moves->rb_moves);
	printf("rrb moves: %d\n", moves->rrb_moves);
	printf("rr moves: %d\n", moves->rr_moves);
	printf("rrr moves: %d\n", moves->rrr_moves);	
	printf("Total moves: %d\n", moves->total_moves);
}

void exec_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int		ma;
	int		mb;

	ma = ft_min(moves->ra_moves, moves->rra_moves);
	mb = ft_min(moves->rb_moves, moves->rrb_moves);
	while (moves->rr_moves > 0)
	{
		op_rotate("rr", a, b);
		moves->rr_moves--;
	}
	while (moves->rrr_moves > 0)
	{
		op_rotate("rrr", a, b);
		moves->rrr_moves--;
	}
	while (ma>0)
	{
		if (moves->ra_moves == ma)
		{
			op_rotate("ra", a, NULL);
			moves->ra_moves--;
		}
		else
		{
			op_rotate("rra", a, NULL);
			moves->rra_moves--;
		}
		ma--;
	}
	while (mb>0)
	{
		if (moves->rb_moves == mb)
		{
			op_rotate("rb", NULL, b);
			moves->rb_moves--;	
		}
		else
		{
			op_rotate("rrb", NULL, b);
			moves->rrb_moves--;
		}
		mb--;	
	}
}

int	*get_params(char **argv, int *size)
{
	int	i;
	int	j;
	int	*numbers;
	char	**cnumbers;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		while (*cnumbers != NULL)
		{
			j++;
			cnumbers++;
		}
		i++;
	}
	*size = j;
	numbers = malloc(j * sizeof(int));
	if (!numbers)
		return (NULL);
	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		while (*cnumbers != NULL)
		{
			numbers[j] = atoi(*cnumbers);
			cnumbers++;
			j++;
		}
		i++;
	}
	return (numbers);
}


int main(int argc, char **argv)
{
    t_stack *a;
    t_stack *b;
    int i;   
	int	*numbers; 
	int	size;

	if (argc == 1)
		return (1);
	numbers = get_params(argv, &size);
	a = new_stack(size);
	b = new_stack(size);
	i = 0;
	while (i < size)
	{
		push_stack(a, numbers[size - 1 - i]);
		i++;
	}	
	if (a->top == 1)
		return (0);
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
	while (b->top > 0)
	{
		op_push("pa", a, b);
	}
	put_min_first(a);
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    return (0);
}
