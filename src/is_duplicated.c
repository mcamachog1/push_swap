/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_duplicated.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 14:20:39 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 14:23:38 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	is_duplicated(int *array, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{			
		if (array[i] == n)
			return (1);
		i++;
	}
	return (0);
}
