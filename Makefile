NAME = push_swap 

SRC = push_swap.c main.c push_cost.c

$(NAME):$(SRC)
	cc -Wall -Werror -Wextra $(SRC) -L ./libft -lft -o $(NAME)

debug: $(SRC)
	cc -Wall -Werror -Wextra -g $(SRC) -L ./libft -lft -o $(NAME)
