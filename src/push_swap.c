/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:06:33 by macamach          #+#    #+#             */
/*   Updated: 2026/01/16 15:50:19 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		size;

	numbers = get_params(argc, argv, &size);
	if (!numbers)
		return (1);
	a = new_stack(size);
	b = new_stack(size);
	load_stack_a(a, numbers, size);
	free(numbers);
	if (is_ordered(a))
		return (free_stacks(a, b, 0), 0);
	if (a->top <= 12)
	{
		sort_by_selection(a, b);
		return (free_stacks(a, b, 0), 0);
	}
	if (!sort_by_cost(a, b))
		return (free_stacks(a, b, 1), 1);
	while (b->top > 0)
		op_push("pa", a, b);
	min_first(a);
	return (free_stacks(a, b, 0), 0);
}
