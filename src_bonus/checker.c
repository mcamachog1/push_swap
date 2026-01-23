/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:43:07 by macamach          #+#    #+#             */
/*   Updated: 2026/01/23 10:27:05 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "checker.h"

int	main(int argc, char **argv)
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
	if (exec_ops(a, b) == 0)
	{
		if (is_ordered(a) && b->top <= 0)
			ft_putstr_fd("OK\n", 1);
		else
			ft_putstr_fd("KO\n", 1);
	}
	return (free_stacks(a, b, 0), 0);
}
