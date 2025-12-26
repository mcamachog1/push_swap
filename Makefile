NAME = a.out

SRC = push_swap.c main.c

$(NAME):$(SRC)
	cc -Wall -Werror -Wextra $(SRC) -L ./libft -lft -o $(NAME)

debug: $(SRC)
	cc -Wall -Werror -Wextra -g $(SRC) -L ./libft -lft -o $(NAME)
