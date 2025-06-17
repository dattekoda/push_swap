NAME := push_swap
CC := cc
CCFLAGS := -Wall -Wextra -Werror
INCDIR := includes

SRCS := srcs/push_swap.c
OBJS := $(SRCS:.c=.o)

LIBFT_DIR := libft
PRINTF_DIR := printf
LIBFT_A := $(LIBFT_DIR)/libft.a
PRINTF_A := $(PRINTF_DIR)/libftprintf.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(PRINTF_A) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) $(PRINTF_A) -I $(INCDIR) -o $@
	@$(MAKE) -C $(LIBFT_DIR) fclean
	@$(MAKE) -C $(PRINTF_DIR) fclean

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

$(PRINTF_A):
	@$(MAKE) -C $(PRINTF_DIR)

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re~