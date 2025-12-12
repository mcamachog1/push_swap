/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:21:32 by macamach          #+#    #+#             */
/*   Updated: 2025/12/12 16:31:56 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>

int	main(int argc, char *argv[])
{
	int	*a;
	int	*b;
	int i;

	printf("Elementos:[%d]\n", argc - 1);
	i = 1;
	while (i < argc)
		printf("Numero:[%s]\n", argv[i++]);
	return (0);
}
