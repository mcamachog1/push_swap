/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:45:51 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 14:09:06 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
		return (0);
}

static int	is_overflow(int factor, int number, char c)
{
	if (factor == 1 && number > (INT_MAX - (c - 48)) / 10)
		return (1);
	if (factor == -1 && number > (INT_MIN + (c - 48)) / (-10))
		return (1);
	return (0);
}

int	ft_atoi_plus(const char *nptr, int *integer)
{
	int	factor;
	int	number;

	number = 0;
	factor = 1;
	while (ft_isspace(*nptr))
		nptr++;
	if (*nptr == '-' || *nptr == '+')
	{
		if (*nptr == '-')
			factor = -1;
		nptr++;
	}
	while (ft_isdigit(*nptr) && *nptr != '\0')
	{
		if (is_overflow(factor, number, *nptr))
			return (1);
		number = number * 10 + (*nptr - 48);
		nptr++;
	}
	if (*nptr != '\0' && !ft_isdigit(*nptr))
		return (1);
	*integer = number * factor;
	return (0);
}
