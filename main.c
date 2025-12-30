#include <stdio.h>
#include <stdlib.h>
#include "libft/libft.h"
#include "push_swap.h"

int	get_index(t_stack *s, int number)
{
	int	i;

	i = 0;
	while(s->array[i] != number && i < s->top)
		i++;
	if (i + 1 == s->top)
		return (-1);
	else
		return (i);
}

int main(int argc, char *argv[])
{
    t_stack *a;
    t_stack *b;
	char	**split;
    int i;


	if (input_error(argc, argv))
	{
		write(2, "Error\n", 6);
		return (1);
	} 
	if (argc == 2)
	{
		split = ft_split(argv[1], ' ');
		i = 0;
		while (split[i] != NULL)
			i++;
		a = new_stack(i);
		b = new_stack(i);
		if (!a || !b)
			return (0);
		while (i > 0)
		{
			push_stack(a, atoi(split[i - 1]));
			i--;
		}
		free(split);	
	}
	else
	{
		a = new_stack(argc - 1);
		b = new_stack(argc - 1);
		if (!a || !b)
			return (0);
		i = argc - 1;
		while (i > 0)
		{
			push_stack(a, atoi(argv[i]));
			i--;
		}
	}
	if (a->top == 1)
	{
		print_stack(a, b);
		return (0);
	}
    	if (a->top == 2)
	{
		if(a->array[0] < a->array[1])
			op_swap("sa", a, NULL);
		print_stack(a, b);
		return (0); 
	}
	if (a->top == 3)
	{
		order_3(a);
		print_stack(a, b);
		return (0);
	}
	op_push("pb", a, b);
	op_push("pb", a, b);
	print_stack(a,b);
	while (a->top > 0)
    	{	
		pop_stack(a, &i);
	} 
	print_stack(a,b);
    free_stack(a);
    free_stack(b);
    free(a);
    free(b);
    return (0);
}
