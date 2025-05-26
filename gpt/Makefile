NAME		:= push_swap
CC		:= cc
CFLAGS		:= -Wall -Wextra -Werror
SRCS		:= srcs/push_swap.c \
		   srcs/input.c \
		   srcs/stack.c \
		   srcs/operations.c \
		   srcs/sort_small.c \
		   srcs/sort_big.c
OBJS		:= $(SRCS:.c=.o)
INCLUDES	:= -I./includes -I./libft

all: $(NAME)

$(NAME): $(OBJS)
	make -C libft
	$(CC) $(CFLAGS) $(OBJS) libft/libft.a $(INCLUDES) -o $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@ $(INCLUDES)

clean:
	rm -f $(OBJS)
	make clean -C libft

fclean: clean
	rm -f $(NAME)
	make fclean -C libft

re:
	$(MAKE) fclean
	$(MAKE) all

bonus: re

.PHONY: all clean fclean re bonus