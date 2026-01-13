/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stacks.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:42:23 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:33:52 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "push_swap.h"

static void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

void	free_stacks(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}
