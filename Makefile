NAME = a.out

$(NAME):
	cc push_swap.c -L./libft -lft -o a.out
