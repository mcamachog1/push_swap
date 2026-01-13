#include "../../push_swap/libft/libft.h"
#include "push_swap.h"

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
	if (a->top <= 12)
	{
		sort_by_selection(a, b);
		return (free_stacks(a, b), 0);
	}
	if (!sort_by_cost(a, b))
		return (free_stacks(a, b), 1);
	while (b->top > 0)
		op_push("pa", a, b);
	min_first(a);
	return (free_stacks(a, b), 0);
}
