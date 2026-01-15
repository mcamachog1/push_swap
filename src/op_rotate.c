/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:25:18 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:25:21 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_rotate(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra", op, 2))
		if (rotate(a) == 0)
			write(1, "ra\n", 3);
	if (!ft_strncmp("rb", op, 2))
		if (rotate(b) == 0)
			write(1, "rb\n", 3);
	if (!ft_strncmp("rra", op, 3))
		if (rrotate(a) == 0)
			write(1, "rra\n", 4);
	if (!ft_strncmp("rrb", op, 3))
		if (rrotate(b) == 0)
			write(1, "rrb\n", 4);
	if (!ft_strncmp("rr", op, 2) && ft_strlen(op) == 2)
		if (rotate(a) == 0 && rotate(b) == 0)
			write(1, "rr\n", 3);
	if (!ft_strncmp("rrr", op, 3) && ft_strlen(op) == 3)
		if (rrotate(a) == 0 && rrotate(b) == 0)
			write(1, "rrr\n", 4);
}
