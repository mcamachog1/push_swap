/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_push.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:25:05 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:25:10 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_push(char *op, t_stack *a, t_stack *b)
{
	int	n;

	if (!ft_strncmp("pa", op, 2))
	{
		if (pop_stack(b, &n) == 0)
			if (push_stack(a, n) == 0)
				write(1, "pa\n", 3);
	}
	if (!ft_strncmp("pb", op, 2))
	{
		if (pop_stack(a, &n) == 0)
			if (push_stack(b, n) == 0)
				write(1, "pb\n", 3);
	}
}
