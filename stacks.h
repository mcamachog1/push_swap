/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stacks.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/07 10:17:48 by macamach          #+#    #+#             */
/*   Updated: 2026/01/07 10:21:16 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef STACKS_H
# define STACKS_H

typedef struct stack
{
	int	*array;
	int	top;
	int	capacity;
}	t_stack;

void order_3(t_stack *s);
int	input_error(int argc, char **argv);
void	print_stack(t_stack *a, t_stack *b);
int	is_ordered(t_stack *s);
t_stack	*new_stack(int size);
int	push_stack(t_stack *s, int number);
int	pop_stack(t_stack *s, int *number);
void	free_stack(t_stack *s);
int	swap(t_stack *s);
void	op_swap(char *op, t_stack *a, t_stack *b);
void	op_push(char *op, t_stack *a, t_stack *b);
void	op_rotate(char *op, t_stack *a, t_stack *b);
#endif
