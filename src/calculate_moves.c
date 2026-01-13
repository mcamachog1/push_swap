/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   calculate_moves.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:10:12 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:10:19 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	calculate_moves(t_moves *moves, t_stack *a, t_stack *b)
{
	int	ma;
	int	mb;
	int	target;

	target = get_target(b, moves->number);
	moves->ra_moves = cost_ra(a, moves->number);
	moves->rra_moves = cost_rra(a, moves->number);
	moves->rb_moves = cost_rb(b, target);
	moves->rrb_moves = cost_rrb(b, target);
	ma = ft_min(moves->ra_moves, moves->rra_moves);
	mb = ft_min(moves->rb_moves, moves->rrb_moves);
	moves->total_moves = ma + mb;
}
