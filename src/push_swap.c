#include "../../push_swap/libft/libft.h"
#include "push_swap.h"

static void	load_stack_a(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push_stack(a, numbers[size - 1 - i]);
		i++;
	}
}

static int	order_less_than_4(t_stack *a)
{
	if (a->top == 1)
		return (0);
	if (a->top == 2)
	{
		if (a->array[0] < a->array[1])
			op_swap("sa", a, NULL);
		return (0);
	}
	if (a->top == 3)
	{
		order_3(a);
		return (0);
	}
	return (1);
}

static t_moves	*get_best_moves(t_stack *a, t_stack *b, t_moves *min_moves)
{
	int		i;
	t_moves	*moves;

	i = a->top - 1;
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
			continue ;
		}
		free(moves);
		i--;
	}
	return (min_moves);
}

static int	sort_stack(t_stack *a, t_stack *b)
{
	int		i;
	t_moves	*min_moves;

	op_push("pb", a, b);
	op_push("pb", a, b);
	while (a->top > 0)
	{
		i = a->top - 1;
		min_moves = new_moves(a->array[i]);
		if (!min_moves)
			return (0);
		min_moves = get_best_moves(a, b, min_moves);
		exec_moves(min_moves, a, b);
		op_push("pb", a, b);
		free(min_moves);
	}
	return (1);
}

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		size;

	if (input_error(argc, argv))
		return (1);
	numbers = get_params(argv, &size);
	a = new_stack(size);
	b = new_stack(size);
	load_stack_a(a, numbers, size);
	free(numbers);
	if (a->top <= 4)
		return (order_less_than_4(a));
	if (!sort_stack(a, b))
		return (1);
	while (b->top > 0)
		op_push("pa", a, b);
	put_min_first(a);
	free_stack(a);
	free_stack(b);
	return (0);
}
