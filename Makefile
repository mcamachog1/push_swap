NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Rutas de la Libft
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

# Archivos de push_swap

SRCS = ./src/calculate_moves.c \
       ./src/cost_ra.c \
       ./src/cost_rb.c \
       ./src/cost_rra.c \
       ./src/cost_rrb.c \
       ./src/exec_moves.c \
       ./src/free_stacks.c \
       ./src/free_string_pointers.c \
       ./src/ft_atoi_plus.c \
       ./src/ft_max.c \
       ./src/ft_min.c \
       ./src/get_best_moves.c \
       ./src/get_index.c \
       ./src/get_params.c \
       ./src/get_target.c \
       ./src/input_error.c \
       ./src/is_duplicated.c \
       ./src/is_ordered.c \
       ./src/load_stack_a.c \
       ./src/min_first.c \
       ./src/new_moves.c \
       ./src/new_stack.c \
       ./src/op_push.c \
       ./src/op_rotate.c \
       ./src/op_swap.c \
       ./src/optimize_moves.c \
       ./src/order_3.c \
       ./src/pop_stack.c \
       ./src/push_stack.c \
       ./src/push_swap.c \
       ./src/rotate.c \
       ./src/rrotate.c \
       ./src/sort_by_cost.c \
       ./src/sort_by_selection.c \
       ./src/swap.c

OBJS        = $(SRCS:.c=.o)

# Incluir los headers (tanto los tuyos como los de libft)
INCLUDES    = -I./src -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

# Regla de depuracion
debug: CFLAGS += -g
debug: re

# REGLA 1: Compilar la Libft usando su propio Makefile
# El flag -C le dice a make que cambie al directorio indicado antes de ejecutar
$(LIBFT):
	@make -C $(LIBFT_DIR)

# REGLA 2: Compilar los .o de push_swap
%.o: %.c
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# REGLA 3: Enlazar todo junto
$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f $(OBJS)
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME)
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re

$(OBJS): ./src/push_swap.h $(LIBFT_DIR)/libft.h
