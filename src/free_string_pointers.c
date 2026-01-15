/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_pointers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:42:45 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 14:44:49 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	free_string_pointers(char **pointers, int error)
{
	int	i;

	if (pointers == NULL)
		return ;
	i = 0;
	while (pointers[i] != NULL)
	{
		free(pointers[i]);
		pointers[i] = NULL;
		i++;
	}
	free(pointers);
	pointers = NULL;
	if (error != 0)
	{
		ft_putstr_fd("Error\n", 2);
		exit(1);
	}
}
