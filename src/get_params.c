/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:45 by macamach          #+#    #+#             */
/*   Updated: 2026/01/13 17:25:19 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "../../push_swap/libft/libft.h"
#include "push_swap.h"

static int	get_size(char **argv)
{
	int		i;
	int		j;
	char	**cnumbers;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		if (!cnumbers)
			return (0);
		while (cnumbers[j] != NULL)
			j++;
		i++;
		free_string_pointers(cnumbers);
	}
	return (j);
}

static int	valid_argument(char *str)
{
	int i;

	i = 0;

	if (str[i] && str[i] == '-')
		i++;	
	while (str[i] && (size_t)i < ft_strlen(str))
	{
		if (!ft_isdigit(str[i]))
			return (0);
		i++;
	}
	return (1);
}

static int	load_numbers(char **argv, int *numbers)
{
	int		i;
	int		j;
	char	**cnumbers;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		if (!cnumbers)
			return (0);
		while (cnumbers[j] != NULL)
		{
			if (!valid_argument(cnumbers[j]))
				return (free_string_pointers(cnumbers), 0);
			numbers[j] = ft_atoi(cnumbers[j]);
			j++;
		}
		i++;
		free_string_pointers(cnumbers);
	}
	return (j);
}

int	*get_params(char **argv, int *size)
{
	int		*numbers;

	*size = get_size(argv);
	if (size == 0)
		return (0);
	numbers = malloc(*size * sizeof(int));
	if (!numbers)
		return (0);
	if (!load_numbers(argv, numbers))
		return (0);
	return (numbers);
}
