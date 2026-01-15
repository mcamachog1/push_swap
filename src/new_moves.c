/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   new_moves.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:24:30 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:24:40 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_moves	*new_moves(int number)
{
	t_moves	*moves;

	moves = (t_moves *)malloc(sizeof(t_moves));
	if (!moves)
		return (0);
	moves->ra_moves = MAX_COST;
	moves->rb_moves = MAX_COST;
	moves->rra_moves = MAX_COST;
	moves->rrb_moves = MAX_COST;
	moves->rr_moves = 0;
	moves->rrr_moves = 0;
	moves->total_moves = MAX_COST;
	moves->number = number;
	return (moves);
}
