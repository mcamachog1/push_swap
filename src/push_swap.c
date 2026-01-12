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
