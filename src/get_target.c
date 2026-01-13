/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_target.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:44:21 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:44:26 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_target(t_stack *b, int number)
{
	int	i;
	int	max;
	int	min;

	i = 0;
	max = b->array[0];
	min = b->array[0];
	while (i < b->top)
	{
		max = ft_max(max, b->array[i]);
		min = ft_min(min, b->array[i]);
		i++;
	}
	if (number > max || number < min)
		return (max);
	if (number > b->array[b->top - 1] && number < b->array[0])
		return (b->array[b->top - 1]);
	while (i > 0)
	{
		i--;
		if (number > b->array[i - 1] && number < b->array[i])
			return (b->array[i - 1]);
	}
	return (-1);
}
