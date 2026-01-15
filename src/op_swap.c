/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_swap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:25:47 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:25:52 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	op_swap(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa", op, 2))
		if (swap(a) == 0)
			write(1, "sa\n", 3);
	if (!ft_strncmp("sb", op, 2))
		if (swap(b) == 0)
			write(1, "sb\n", 3);
	if (!ft_strncmp("ss", op, 2))
		if (swap(a) == 0 && swap(b) == 0)
			write(1, "ss\n", 3);
}
