/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_by_selection.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:27:57 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:34:10 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	sort_by_selection(t_stack *a, t_stack *b)
{
	if (a->top > 3)
	{
		while (a->top > 3)
		{
			min_first(a);
			op_push("pb", a, b);
		}
		order_3(a);
		while (b->top > 0)
			op_push("pa", a, b);
		return ;
	}
	if (a->top == 3)
		order_3(a);
	if (a->top == 2)
		if (a->array[1] > a->array[0])
			op_swap("sa", a, NULL);
}
