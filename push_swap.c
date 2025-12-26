/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/12 16:21:32 by macamach          #+#    #+#             */
/*   Updated: 2025/12/18 15:28:07 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"


void	print_stack(t_stack *a, t_stack *b)
{
	int	i;
	int	j;

	i = a->top - 1;
	j = b->top - 1;
	while (i >= 0 || j >= 0)
	{
		if (i >= 0 )
			printf("%i  ", a->array[i]);
		else
			printf("   ");
		if (j >= 0)
			printf("%i  ", b->array[j]);
		else
			printf("   ");
		printf("\n");
		i--;
		j--;
	}
	printf("\n");
	printf("-  -\n");
	printf("a  b\n");
}

t_stack	*new_stack(int size)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->top = 0;
	s->capacity = size;
	s->array = malloc(size * sizeof(int));
	if (!s->array)
		return (NULL);
	return (s);
}

int	push_stack(t_stack *s, int number)
{
	if (s->top >= s->capacity)
		return (1);
	s->array[s->top] = number;
	s->top++;
	return (0);
}

int	pop_stack(t_stack *s, int *number)
{
	if (s->top <= 0)
		return (1);
	s->top--;
	*number = s->array[s->top];
	return (0);
}

void	free_stack(t_stack *s)
{
	free(s->array);
}

void	swap(t_stack *s)
{
	int	temp_1;
	int	temp_2;

	if (s->top <= 1)
		return ;
	pop_stack(s, &temp_1);
	pop_stack(s, &temp_2);
	push_stack(s, temp_1);
	push_stack(s, temp_2);
}

void	op_swap(char *op, t_stack *a, t_stack *b)
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

void	rotate(t_stack *s)
{
	int	temp;
	int	i;

	temp = s->array[s->top - 1];
	i = s->top - 1;
	while (i > 0)
	{
		s->array[i] = s->array[i - 1];
		i--;
	}
	s->array[0] = temp;
}

void	rrotate(t_stack *s)
{
	int	temp;
	int	i;

	temp = s->array[0];
	i = 0;
	while (i < s->top - 1)
	{
		s->array[i] = s->array[i + 1];
		i++;
	}
	s->array[s->top - 1] = temp;
}

void	op_push(char *op, t_stack *a, t_stack *b)
{
	int	n;

	if (!ft_strncmp("pa", op, 2)) 
	{
		if (pop_stack(b, &n) == 0)
			if (push_stack(a, n) == 0)
				write(1, "pa\n", 3);
	}
	if (!ft_strncmp("pb", op, 2)) 
	{
		if (pop_stack(a, &n) == 0)
			if (push_stack(b, n) == 0)
				write(1, "pb\n", 3);
	}
}

void	op_rotate(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra", op, 2)) 
		if (a->top > 0)
			rotate(a);
	if (!ft_strncmp("rra", op, 3)) 
		if (a->top > 0)
			rrotate(a);
	if (!ft_strncmp("rb", op, 2)) 
		if (a->top > 0)
			rotate(b);
	if (!ft_strncmp("rrb", op, 3)) 
		if (a->top > 0)
			rrotate(b);
	if (!ft_strncmp("rr", op, 2) && ft_strlen(op) == 2) 
		if (a->top > 0 && b->top > 0)
		{
			rotate(a);
			rotate(b);
		}
	if (!ft_strncmp("rrr", op, 3)) 
		if (a->top > 0 && b->top > 0)
		{
			rrotate(a);
			rrotate(b);
		}
}
