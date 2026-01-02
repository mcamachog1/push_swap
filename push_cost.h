#ifndef PUT_COST_H
# define PUT_COST_H

# ifndef MAX_COST
#  define MAX_COST 1000
# endif

#include "push_swap.h"

int	ft_min(int a, int b);
int	ft_max(int a, int b);
int	get_index(t_stack *s, int number);
int	get_target(t_stack *s, int number);
int	cost_ra(t_stack *a, int n);
int	cost_rra(t_stack *a, int n);
int	cost_rb(t_stack *b, int n);
int	cost_rrb(t_stack *b, int n);

#endif