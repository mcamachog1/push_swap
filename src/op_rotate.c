#include "../../push_swap/libft/libft.h"
#include "push_swap.h"

void	op_rotate(char *op, t_stack *a, t_stack *b)
{
	if (!ft_strncmp("ra", op, 2))
		if (rotate(a) == 0)
			write(1, "ra\n", 3);
	if (!ft_strncmp("rb", op, 2))
		if (rotate(b) == 0)
			write(1, "rb\n", 3);
	if (!ft_strncmp("rra", op, 3))
		if (rrotate(a) == 0)
			write(1, "rra\n", 4);
	if (!ft_strncmp("rrb", op, 3))
		if (rrotate(b) == 0)
			write(1, "rrb\n", 4);
	if (!ft_strncmp("rr", op, 2) && ft_strlen(op) == 2)
		if (rotate(a) == 0 && rotate(b) == 0)
			write(1, "rr\n", 3);
	if (!ft_strncmp("rrr", op, 3) && ft_strlen(op) == 3)
		if (rrotate(a) == 0 && rrotate(b) == 0)
			write(1, "rrr\n", 4);
}