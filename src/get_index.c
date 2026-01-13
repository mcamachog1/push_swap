/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_index.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:35 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 15:43:38 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_index(t_stack *s, int number)
{
	int	i;

	i = 0;
	while (s->array[i] != number && i < s->top)
		i++;
	if (i == s->top)
		return (-1);
	else
		return (i);
}
