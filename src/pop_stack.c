/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pop_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:26:32 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:26:34 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	pop_stack(t_stack *s, int *number)
{
	if (s->top <= 0)
		return (1);
	s->top--;
	*number = s->array[s->top];
	return (0);
}
