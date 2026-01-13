/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:28:05 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:28:07 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	swap(t_stack *s)
{
	int	temp_1;
	int	temp_2;

	if (s->top <= 1)
		return (1);
	pop_stack(s, &temp_1);
	pop_stack(s, &temp_2);
	push_stack(s, temp_1);
	push_stack(s, temp_2);
	return (0);
}
