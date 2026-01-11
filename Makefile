NAME = push_swap 

SRC = ./src/calculate_moves.c  ./src/ft_min.c       ./src/op_rotate.c       ./src/push_stack.c \
./src/cost_ra.c          ./src/get_index.c    ./src/op_swap.c         ./src/push_swap.c \
./src/cost_rb.c          ./src/get_target.c   ./src/optimize_moves.c  ./src/put_min_first.c \
./src/cost_rra.c         ./src/input_error.c  ./src/order_3.c         ./src/rotate.c \
./src/cost_rrb.c         ./src/is_ordered.c   ./src/pop_stack.c       ./src/rrotate.c \
./src/exec_moves.c       ./src/new_moves.c    ./src/pre_order.c       ./src/swap.c \
./src/free_stack.c       ./src/new_stack.c    ./src/print_moves.c \
./src/ft_max.c           ./src/op_push.c      ./src/print_stack.c	./src/get_params.c

$(NAME):$(SRC)
	cc -Wall -Werror -Wextra $(SRC) -L ./libft -lft -o $(NAME)

debug: $(SRC)
	cc -Wall -Werror -Wextra -g $(SRC) -L ./libft -lft -o $(NAME)
