/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ordered.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:53 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:44:55 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	is_ordered(t_stack *s)
{
	int	i;

	if (s->top <= 1)
		return (1);
	i = s->top - 1;
	while (i > 0)
	{
		if (s->array[i] > s->array[i - 1])
			return (0);
		i--;
	}
	return (1);
}
