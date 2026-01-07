/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nums_generator.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 12:33:11 by macamach          #+#    #+#             */
/*   Updated: 2026/01/07 13:44:53 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int	is_duplicate(int *array, int n, int size)
{
	int	i;

	i = 0;
	while (i < size)
	{
		if (n == array[i])
			return (1);
		i++;
	}
	return (0);
}

void	print_numbers(int *numbers, int n)
{
	int	i;

	i = 0;
	while (i < n)
	{
		printf("%d ", numbers[i]);
		i++;
	}
	printf("\n");
}

int	*ft_random(int n)
{
	int	num;
	int	i;
	int	j;
	int	*numbers;

	numbers = malloc(sizeof(int) * n);
	srand(time(NULL));
	i = 0;
	j = 0;
	while (i < 1000 && j < n)
	{
		num = (rand() % (1999)) + (-999);
		if (!is_duplicate(numbers, num, n))
		{
			numbers[j] = num;
			j++;
		}
		i++;
	}
	return (numbers);
}

int	main(int argc, char **argv)
{
	int	*numbers;

	if (argc != 2)
		return (1);
	numbers = ft_random(atoi(argv[1]));
	print_numbers(numbers, atoi(argv[1]));
	free(numbers);
	return (0);
}
