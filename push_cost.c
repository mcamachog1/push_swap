#include "push_cost.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

int	ft_max(int a, int b)
{
	if (a > b)
		return (a);
	else
		return (b);
}

int	get_index(t_stack *s, int number)
{
	int	i;

	i = 0;
	while(s->array[i] != number && i < s->top)
		i++;
	if (i == s->top)
		return (-1);
	else
		return (i);
}

int	get_target(t_stack *b, int number)
{
	int i;
	int max;
	int min;

	i = 0;
	max = b->array[0];
	min = b->array[0];
	while (i < b->top)
	{
		max = ft_max(max, b->array[i]);
		min = ft_min(min, b->array[i]);
		i++;
	}
	if (number > max || number < min)
		return (max);
	if (number > b->array[b->top - 1] && number < b->array[0])
		return (b->array[b->top - 1]);	
	while (i > 0)
	{
		if (number > b->array[i] && number < b->array[i - 1])
			return (b->array[i - 1]);
		i--;
	}
	return (-1);
}

int	cost_ra(t_stack *a, int n)
{
	return (a->top - get_index(a, n) - 1);
}

int	cost_rra(t_stack *a, int n)
{
	return (get_index(a, n) + 1);
}

int	cost_rb(t_stack *b, int n)
{
	return (cost_ra(b, n));
}

int	cost_rrb(t_stack *b, int n)
{
	return (cost_rra(b, n));
}