/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   op_utils.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:10 by macamach          #+#    #+#             */
/*   Updated: 2026/01/23 10:27:57 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include "checker.h"

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
	if (!ft_strncmp("rr", op, 2) && ft_strlen(op) == 3)
	{
		rotate(a);
		rotate(b);
	}
	if (!ft_strncmp("rrr", op, 3) && ft_strlen(op) == 4)
	{
		rrotate(a);
		rrotate(b);
	}
}

int op_valid(char *op)
{
	if (ft_strncmp("sa", op, 2) == 0 || ft_strncmp("sb", op, 2) == 0)
		return (1);
	if (ft_strncmp("pa", op, 2) == 0 || ft_strncmp("pb", op, 2) == 0)
		return (1);
	if (ft_strncmp("ra", op, 2) == 0 || ft_strncmp("rb", op, 2) == 0)
		return (1);
	if (ft_strncmp("ss", op, 2) == 0)
		return (1);
	if (ft_strncmp("rra", op, 3) == 0 || ft_strncmp("rrb", op, 3) == 0)
		return (1);
	if (ft_strncmp("rr", op, 2) == 0 && ft_strlen(op) == 3)
		return (1);
	if (ft_strncmp("rrr", op, 3) == 0  && ft_strlen(op) == 4)
		return (1);
	return (0);
}

int	exec_ops(t_stack *a, t_stack *b)
{
	int		fd;
	char	*op;

	fd = 0;
	while (1)
	{
		op = get_next_line(fd);
		if (op == NULL)
			return (0);
		do_op_swap(op, a, b);
		do_op_push(op, a, b);
		do_op_rotate(op, a, b);
		if (op_valid(op) == 0)
		{
			free(op);
			ft_putstr_fd("Error\n", 2);
			return (1);
		}
		free(op);
	}
}
