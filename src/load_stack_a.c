/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   load_stack_a.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:45:11 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:45:17 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	load_stack_a(t_stack *a, int *numbers, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		push_stack(a, numbers[size - 1 - i]);
		i++;
	}
}
