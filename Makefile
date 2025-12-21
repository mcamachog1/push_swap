NAME = a.out

SRC = push_swap.c

$(NAME):$(SRC)
	cc $(SRC) -L ./libft -lft -o a.out

debug: $(SRC)
	cc -g $(SRC) -L ./libft -lft -o a.out
