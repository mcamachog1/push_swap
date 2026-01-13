/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rrotate.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:27:32 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:27:36 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	rrotate(t_stack *s)
{
	int	temp;
	int	i;

	if (s->top <= 1)
		return (1);
	temp = s->array[0];
	i = 0;
	while (i < s->top - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->top - 1] = temp;
	return (0);
}
