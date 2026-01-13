/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:27:00 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:27:06 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	push_stack(t_stack *s, int number)
{
	if (s->top >= s->capacity)
		return (1);
	s->array[s->top] = number;
	s->top++;
	return (0);
}
