/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_params.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/13 15:43:45 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 14:43:29 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"

static int	get_size(char **argv)
{
	int		i;
	int		j;
	int		size;
	char	**cnumbers;

	i = 1;
	size = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		if (!cnumbers)
			return (0);
		j = 0;
		while (cnumbers[j] != NULL)
		{
			size++;
			j++;
		}
		i++;
		free_string_pointers(cnumbers, 0);
	}
	return (size);
}

static int	valid_argument(char *str, int *numbers, int size)
{
	int	i;
	int	n;

	i = 0;
	if (str[i] && (str[i] == '-' || str[i] == '+'))
		i++;
	if (ft_strlen(&str[i]) > 10)
		return (0);
	if (ft_atoi_plus(str, &n) != 0)
		return (0);
	if (is_duplicated(numbers, ft_atoi(str), size))
		return (0);
	return (1);
}

static int	load_numbers(char **argv, int *numbers)
{
	int		i;
	int		j;
	char	**cnumbers;
	char	**temp;

	i = 1;
	j = 0;
	while (argv[i] != NULL)
	{
		cnumbers = ft_split(argv[i], ' ');
		if (!cnumbers)
			return (0);
		temp = cnumbers;
		while (*cnumbers != NULL)
		{
			if (!valid_argument(*cnumbers, numbers, j))
				return (free_string_pointers(temp, 1), 0);
			numbers[j] = ft_atoi(*cnumbers);
			j++;
			cnumbers++;
		}
		i++;
		free_string_pointers(temp, 0);
	}
	return (j);
}

int	*get_params(int argc, char **argv, int *size)
{
	int		*numbers;

	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (0);
	}
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
