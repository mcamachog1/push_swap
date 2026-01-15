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

#include <stdlib.h>
#include "push_swap.h"
#include "libft.h"

static void	free_stack(t_stack *s)
{
	free(s->array);
	free(s);
}

void	free_stacks(t_stack *a, t_stack *b, int error)
{
	free_stack(a);
	free_stack(b);
	if (error != 0)
		ft_putstr_fd("Error\n", 2);
}
