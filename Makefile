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

OBJS = $(SRCS:.c=.o)

# Incluir los headers (tanto los tuyos como los de libft)
HEADERS = ./src/push_swap.h ./libft/libft.h
INCLUDES    = -I./src -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

# Regla de depuracion
debug: CFLAGS += -g
debug: re

# REGLA 1: Compilar la Libft usando su propio Makefile
# El flag -C le dice a make que cambie al directorio indicado antes de ejecutar
$(LIBFT):
	@make -C $(LIBFT_DIR)

# REGLA 2: Compil)ar los .o de push_swap
%.o: %.c $(HEADERS)
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

.PHONY: all clean fclean re bonus debug $(LIBFT)

$(OBJS): ./src/push_swap.h $(LIBFT_DIR)/libft.h


# ----- BONUS ------- 
BONUS_NAME = checker

bonus: $(BONUS_NAME)

SRCS_BONUS = ./src/calculate_moves.c \
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
       ./src/rotate.c \
       ./src/rrotate.c \
       ./src/sort_by_cost.c \
       ./src/sort_by_selection.c \
       ./src/swap.c \
	./src_bonus/checker.c \
	./src_bonus/op_utils.c \
	./src_bonus/print_stack.c #Eliminar

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES_BONUS = $(INCLUDES) -I./src_bonus

$(BONUS_NAME): $(OBJS_BONUS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

debug_bonus: CFLAGS += -g
debug_bonus: re_bonus 

clean_bonus:
	rm -f $(OBJS_BONUS) 

fclean_bonus: clean_bonus
	rm -f $(BONUS_NAME) 

re_bonus: fclean_bonus bonus

	
# Change BUFFERSIZE: make re -C ./libft CFLAGS="-Wall -Wextra -Werror -D BUFFER_SIZE=1000"
	
