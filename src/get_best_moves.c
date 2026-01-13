/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_best_moves.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:26 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:43:29 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdlib.h>

t_moves	*get_best_moves(t_stack *a, t_stack *b, t_moves *min_moves)
{
	int		i;
	t_moves	*moves;

	i = a->top - 1;
	while (i >= 0)
	{
		moves = new_moves(a->array[i]);
		if (!moves)
			return (0);
		calculate_moves(moves, a, b);
		optimize_moves(moves);
		if (moves->total_moves < min_moves->total_moves)
		{
			free(min_moves);
			min_moves = moves;
			i--;
			continue ;
		}
		free(moves);
		i--;
	}
	return (min_moves);
}
