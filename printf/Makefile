NAME	:= libftprintf.a
CC		:= cc
CFLAGS	:= -Wall -Wextra -Werror -Iincludes
AR		:= ar rcs

SRCS := srcs/ft_format.c srcs/ft_printf.c \
srcs/handle.c srcs/output.c \
srcs/libft.c srcs/ft_utils.c \
srcs/ready.c srcs/count.c	\
srcs/libft_min_max.c

OBJS := $(SRCS:.c=.o)

.PHONY: all clean fclean re

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $@ $^

bonus: $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all