/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_stack.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:52 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:24:54 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

t_stack	*new_stack(int size)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->top = 0;
	s->capacity = size;
	s->array = malloc(size * sizeof(int));
	if (!s->array)
		return (0);
	return (s);
}
