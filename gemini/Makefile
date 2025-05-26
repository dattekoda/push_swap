# push_swap/Makefile
NAME = push_swap
BONUS_NAME = checker

CC = cc
CFLAGS = -Wall -Wextra -Werror -Iinclude -Ilibft
RM = rm -f

LIBFT_DIR = libft
LIBFT = $(LIBFT_DIR)/libft.a

# Source files for push_swap (mandatory part)
SRCS_DIR = src
SRCS_FILES = main.c \
             error.c \
             parsing_args.c \
             parsing_validate.c \
             stack_init.c \
             stack_utils.c \
             stack_ops_swap.c \
             stack_ops_push.c \
             stack_ops_rotate.c \
             stack_ops_rev_rotate.c \
             sort_small_utils.c \
             sort_three.c \
             sort_four_five.c \
             sort_radix_utils.c \
             sort_radix.c
SRCS = $(addprefix $(SRCS_DIR)/, $(SRCS_FILES))
OBJS = $(SRCS:.c=.o)

# Source files for checker (bonus part)
BONUS_SRCS_DIR = bonus
BONUS_SRCS_FILES = checker_main.c \
                   checker_reader.c \
                   checker_ops_apply.c \
                   checker_utils.c
# Bonus might reuse some src files if structured for it (e.g. generic stack ops)
# For simplicity here, assuming bonus has its own main and calls shared stack logic.
# If checker reuses src .o files, list them explicitly or adjust.
# This example assumes checker links against push_swap's objects + its own.
# A cleaner way for bonus is to have its own object files, and link common objects.
# For now, let's make bonus depend on push_swap objects + its specific objects.
BONUS_SRCS_SPECIFIC = $(addprefix $(BONUS_SRCS_DIR)/, $(BONUS_SRCS_FILES))
BONUS_OBJS_SPECIFIC = $(BONUS_SRCS_SPECIFIC:.c=.o)

# Ensure all necessary objects for checker are compiled.
# This might include some from SRCS_DIR if they are shared and not linked via push_swap $(NAME)
# For this example, we'll assume checker will compile its own objects and link with libft.
# The 'print' flag in operations allows reuse.
# So checker will use the same stack_ops_*.o files from mandatory.

all: $(NAME)

$(NAME): $(OBJS) $(LIBFT)
	$(CC) $(CFLAGS) $(OBJS) -L$(LIBFT_DIR) -lft -o $(NAME)

bonus: $(LIBFT) $(OBJS) $(BONUS_OBJS_SPECIFIC)
	$(CC) $(CFLAGS) $(OBJS) $(BONUS_OBJS_SPECIFIC) -L$(LIBFT_DIR) -lft -o $(BONUS_NAME)

$(LIBFT):
	make -C $(LIBFT_DIR)

# Rule for compiling .c files in src and bonus directories
$(SRCS_DIR)/%.o: $(SRCS_DIR)/%.c include/push_swap.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

$(BONUS_SRCS_DIR)/%.o: $(BONUS_SRCS_DIR)/%.c include/push_swap.h libft/libft.h
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	make -C $(LIBFT_DIR) clean
	$(RM) $(OBJS) $(BONUS_OBJS_SPECIFIC)

fclean: clean
	make -C $(LIBFT_DIR) fclean
	$(RM) $(NAME) $(BONUS_NAME)

re: fclean all

.PHONY: all bonus clean fclean re