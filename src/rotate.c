/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:27:25 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:27:26 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rotate(t_stack *s)
{
	int	temp;
	int	i;

	if (s->top <= 1)
		return (1);
	temp = s->array[s->top - 1];
	i = s->top - 1;
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = temp;
	return (0);
}
