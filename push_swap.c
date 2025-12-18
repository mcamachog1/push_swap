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

int	main(int argc, char *argv[])
{
	t_stack	*a;
	t_stack	*b;
	int		i;

	if (argc <  1)
	{
		printf("Arguments error\n");
		return (0);
	}
	a = new_stack(argc - 1);
	b = new_stack(argc - 1);
	if (!a || !b)
		return (0);
	printf("Elementos:[%d]\n", argc - 1);
	i = argc - 1;
	while (i > 0)
	{
		push_stack(a, atoi(argv[i]));
		i--;
	}
	printf("inicio\n");
	print_stack(a);
	printf("sa\n");
	operation("sa", a, b);
	print_stack(a);
	printf("sa\n");
	operation("sa", a, b);
	print_stack(a);
	free_stack(a);
	free_stack(b);
	free(a);
	free(b);
	return (0);
}

void	print_stack(t_stack *s)
{
	int	i;

	i = s->top - 1;
	while (i >= 0)
	{
		printf("%i\n", s->array[i]);
		i--;
	}
}

t_stack	*new_stack(int size)
{
	t_stack	*s;

	s = malloc(sizeof(t_stack));
	if (!s)
		return (0);
	s->top = 0;
	s->array = malloc(size * sizeof(int));
	if (!s->array)
		return (NULL);
	return (s);
}

void	push_stack(t_stack *s, int number)
{
	s->array[s->top] = number;
	s->top++;
}

int	pop_stack(t_stack *s)
{
	int	number;
	
	s->top--;
	number = s->array[s->top];
	return (number);
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
	temp_1 = pop_stack(s);
	temp_2 = pop_stack(s);
	push_stack(s, temp_1);
	push_stack(s, temp_2);
}

void	rotate(t_stack *s)
{
	int	temp;
	int	i;

	i = s->top;
	temp = pop_stack(s);
	while (i >= 0)
	{
		

	}
	
}

void	op_swap(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("sa", op, ft_strlen(op))) 
		swap(a);
	if (!ft_strncmp("sb", op, ft_strlen(op))) 
		swap(b);
	if (!ft_strncmp("ss", op, ft_strlen(op))) 
	{
		swap(a);
		swap(b);
	}
}

void	op_push(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("pa", op, ft_strlen(op))) 
	{
		if (b->top > 0)
			push_stack(a, pop_stack(b));
	}
	if (!ft_strncmp("pb", op, ft_strlen(op))) 
	{
		if (a->top > 0)
			push_stack(a, pop_stack(b));
	}
}

void	op_rotate(char *op, t_stack *a, t_stack *b)
{
	int	temp;
	int	i;

	if (!ft_strncmp("ra", op, ft_strlen(op))) 
		
	
}
