NAME := push_swap
CC := cc
CCFLAGS := -Wall -Wextra -Werror
INC := includes/push_swap.h

SRCS := srcs/err.c srcs/is_validate.c srcs/main.c \
		srcs/parse.c srcs/push_swap_more.c \
		srcs/push_swap_utils.c srcs/push_swap.c \
		srcs/qsort.c srcs/rr.c srcs/sa_r.c \
		srcs/stack_utils.c srcs/stack_utils2.c \
		srcs/pa_pb.c

BONUS := bonus/main_bonus.c bonus/pa_pb_bonus.c \
		bonus/rr_bonus.c bonus/err_bonus.c \
		bonus/sa_r_bonus.c bonus/is_validate_bonus.c \
		bonus/parse_bonus.c bonus/qsort_bonus.c \
		bonus/stack_utils_bonus.c \
		bonus/stack_utils2_bonus.c \
		libft/get_next_line.c

OBJS := $(SRCS:.c=.o)
OBJS_BONUS := $(BONUS:.c=.o)

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