/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:42:23 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 14:41:24 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static void	free_stack(t_stack *s)
{
	free(s->array);
	s->array = NULL;
	free(s);
	s = NULL;
}

void	free_stacks(t_stack *a, t_stack *b, int error)
{
	if (a != NULL)
	{
		free_stack(a);
		a = NULL;
	}
	if (b != NULL)
	{
		free_stack(b);
		b = NULL;
	}
	if (error != 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
