/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/16 10:22:22 by macamach          #+#    #+#             */
/*   Updated: 2025/12/18 14:48:26 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

typedef struct stack
{
	int	*array;
	int	top;
	int	capacity;
}	t_stack;

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
