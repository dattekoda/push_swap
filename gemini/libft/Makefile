# push_swap/libft/Makefile
NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
AR = ar rcs
RM = rm -f

SRCS_FILES = ft_atoi_checked.c \
             ft_isdigit.c \
             ft_putstr_fd.c \
             ft_strlen.c \
             ft_strcmp.c \
			 ft_strdup.c \
             ft_lstnew.c \
             ft_lstadd_back.c \
             ft_lstclear.c \
             ft_lstsize.c

SRCS = $(SRCS_FILES)
OBJS = $(SRCS:.c=.o)

all: $(NAME)

$(NAME): $(OBJS)
	$(AR) $(NAME) $(OBJS)

%.o: %.c libft.h
	$(CC) $(CFLAGS) -c $< -o $@ -I.

clean:
	$(RM) $(OBJS)

fclean: clean
	$(RM) $(NAME)

re: fclean all

.PHONY: all clean fclean re