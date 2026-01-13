/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_string_pointers.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:42:45 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 16:33:21 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	free_string_pointers(char **pointers)
{
	int	i;

	i = 0;
	while (pointers[i] != NULL)
	{
		free(pointers[i]);
		i++;
	}
	free(pointers);
}
