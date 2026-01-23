/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: macamach <mcamach@student.42porto.com>     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/21 11:33:50 by macamach          #+#    #+#             */
/*   Updated: 2026/01/23 10:28:17 by macamach         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CHECKER_H
# define CHECKER_H

# include "push_swap.h"

void	do_op_swap(char *op, t_stack *a, t_stack *b);
void	do_op_push(char *op, t_stack *a, t_stack *b);
void	do_op_rotate(char *op, t_stack *a, t_stack *b);
int	exec_ops(t_stack *a, t_stack *b);
int	op_valid(char *op);

#endif
