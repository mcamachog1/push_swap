/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com      +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 11:43:07 by macamach          #+#    #+#             */
/*   Updated: 2026/01/20 16:19:41 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include "libft.h"
#include "push_swap.h"


void	do_op_swap(char *op, t_stack *a, t_stack *b);
void	do_op_push(char *op, t_stack *a, t_stack *b);
void	do_op_rotate(char *op, t_stack *a, t_stack *b);

int	main(int argc, char **argv)
{
	int		fd;
	char	*op;
	t_stack	*a;
	t_stack	*b;
	int		*numbers;
	int		size;

	numbers = get_params(argc, argv, &size);
	if (!numbers)
		return (1);
	a = new_stack(size);
	b = new_stack(size);
	load_stack_a(a, numbers, size);
	free(numbers);
//	fd = 0;
	fd = open("file.txt", O_RDONLY);
	while (1)
	{
		op = get_next_line(fd);
		if (op == NULL)
			break ;
		do_op_swap(op, a, b);
		do_op_push(op, a, b);
		do_op_rotate(op, a, b);
		free(op);
	}
	if (is_ordered(a) && b->top <= 0)
		ft_putstr_fd("OK\n", 1);
	else
		ft_putstr_fd("KO\n", 1);
	return (0);
}

void	do_op_swap(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa", op, 2))
		swap(a);
	if (!ft_strncmp("sb", op, 2))
		swap(b);
	if (!ft_strncmp("ss", op, 2))
	{
		swap(a); 
		swap(b);
	}
}

void	do_op_push(char *op, t_stack *a, t_stack *b)
{
	int	n;

	if (!ft_strncmp("pa", op, 2))

		if (pop_stack(b, &n) == 0)
			push_stack(a, n);
	if (!ft_strncmp("pb", op, 2))
		if (pop_stack(a, &n) == 0)
			push_stack(b, n);
}


void	do_op_rotate(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra", op, 2))
		rotate(a);
	if (!ft_strncmp("rb", op, 2))
		rotate(b);
	if (!ft_strncmp("rra", op, 3))
		rrotate(a);
	if (!ft_strncmp("rrb", op, 3))
		rrotate(b);
	if (!ft_strncmp("rr", op, 2) && ft_strlen(op) == 2)
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strncmp("rrr", op, 3) && ft_strlen(op) == 3)
	{
		rrotate(a);
		rrotate(b);
	}
}
