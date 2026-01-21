NAME        = push_swap
CC          = cc
CFLAGS      = -Wall -Wextra -Werror

# Libft
LIBFT_DIR   = ./libft
LIBFT       = $(LIBFT_DIR)/libft.a

# push_swap

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

# Incluide headers
HEADER_PUSH_SWAP = ./src/push_swap.h 
HEADER_LIBFT = ./libft/libft.h 
INCLUDES    = -I./src -I$(LIBFT_DIR)

all: $(LIBFT) $(NAME)

# For debug
debug: CFLAGS += -g
debug: re

# Compile Libft
$(LIBFT): 
	@make -C $(LIBFT_DIR)

# Compile .o push_swap
%.o: %.c $(HEADER_PUSH_SWAP)
	$(CC) $(CFLAGS) $(INCLUDES) -c $< -o $@

# LINK 
$(NAME): $(OBJS) $(HEADER_PUSH_SWAP)
	$(CC) $(CFLAGS) $(OBJS) $(LIBFT) -o $(NAME)

clean:
	rm -f ./src/push_swap.o 
	rm -f $(OBJS_BONUS) 
	@make -C $(LIBFT_DIR) clean

fclean: clean
	rm -f $(NAME) 
	rm -f $(BONUS_NAME) 
	@make -C $(LIBFT_DIR) fclean

re: fclean all

.PHONY: all clean fclean re bonus debug degug_bonus re_bonus $(LIBFT)


# ---------------------- BONUS -------------------#

BONUS_NAME = checker

HEADER_BONUS = ./src_bonus/checker.h 

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
       ./src_bonus/op_utils.c 

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

INCLUDES_BONUS = $(INCLUDES) -I./src_bonus

bonus: $(BONUS_NAME)

# Compile .o bonus  
%.o: %.c $(HEADER_BONUS) 
	$(CC) $(CFLAGS) $(INCLUDES_BONUS) -c $< -o $@

# Link 
$(BONUS_NAME): $(OBJS_BONUS) $(HEADER_BONUS)
	$(CC) $(CFLAGS) $(OBJS_BONUS) $(LIBFT) -o $(BONUS_NAME)

debug_bonus: CFLAGS += -g
debug_bonus: re_bonus 
re_bonus: fclean all bonus
	
# Change BUFFERSIZE: make re -C ./libft CFLAGS="-Wall -Wextra -Werror -D BUFFER_SIZE=1000"
