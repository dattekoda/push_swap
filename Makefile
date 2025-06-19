NAME := push_swap
CC := cc
CCFLAGS := -Wall -Wextra -Werror
INC := includes/push_swap.h

SRCS := srcs/err.c srcs/is_validate.c srcs/main.c \
		srcs/parse.c srcs/push_swap_more.c \
		srcs/push_swap_utils.c srcs/push_swap.c \
		srcs/qsort.c srcs/rr.c srcs/sa_r.c \
		srcs/stack_utils.c srcs/stack_utils2.c
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -o $@
	@$(MAKE) -C $(LIBFT_DIR) fclean

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re