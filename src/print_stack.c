/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_stack.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 16:26:52 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:26:55 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"
#include <stdio.h>

void	print_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->top - 1;
	j = b->top - 1;
	printf("\n");
	while (i >= 0 || j >= 0)
	{
		if (i >= 0)
			printf("%i  ", a->array[i]);
		else
			printf("   ");
		if (j >= 0)
			printf("%i  ", b->array[j]);
		else
			printf("   ");
		printf("\n");
		i--;
		j--;
	}
	printf("\n");
	printf("-  -\n");
	printf("a  b\n");
}
