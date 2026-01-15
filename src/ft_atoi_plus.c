/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi_plus.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/15 10:45:51 by macamach          #+#    #+#             */
/*   Updated: 2026/01/15 12:09:11 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "libft.h"

static int	ft_isspace(char c)
{
	if (c == 32 || (c >= 9 && c <= 13))
		return (1);
	else
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
	if (ft_strlen(nptr) > 10)
		return (1);
	while (ft_isdigit(*nptr))
	{
		if (factor == 1)
		{
			if (number > (2147483647 - (*nptr - 48)) / 10)
				return (1);
		}
		else
		{
			if (number > (2147483648 - (*nptr - 48)) / 10)
				return (1);
		}
		number = number * 10 + (*nptr - 48);
		nptr++;
	}
	*integer = number * factor;
	return (0);
}

int main() 
{
	int integer;
	int i;
	char	str[15] = "-214748364";

	i = 0;
	while (str[i])
	{
		if (ft_atoi_plus(str, &integer) == 0)
			printf("%i\n", integer);
		else
		{
			printf("overflow con el str:%s", str);
			return (1);
		}
		i = ft_strlen(str);
		if (i < 15 - 1)
			str[i] = '8';
	}
    return 0;
}
