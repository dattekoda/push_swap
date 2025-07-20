NAME := push_swap
BONUS_NAME := checker
CC := cc
CCFLAGS := -Wall -Wextra -Werror

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
		bonus/stack_utils2_bonus.c

OBJS := $(SRCS:.c=.o)
BONUS_OBJS := $(BONUS:.c=.o)

LIBFT_DIR := libft
LIBFT_A := $(LIBFT_DIR)/libft.a

all: $(NAME)

$(NAME): $(LIBFT_A) $(OBJS)
	$(CC) $(CCFLAGS) $(OBJS) $(LIBFT_A) -I includes/push_swap.h -o $@

$(LIBFT_A):
	@$(MAKE) -C $(LIBFT_DIR)

bonus: $(BONUS_NAME)

$(BONUS_NAME): $(BONUS_OBJS) $(LIBFT_A)
	$(CC) $(CCFLAGS) $(BONUS_OBJS) $(LIBFT_A) -I includes/push_swap_bonus.h -o $@

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS) $(BONUS_OBJS)
	@$(MAKE) -C $(LIBFT_DIR) fclean

fclean: clean
	rm -f $(NAME) $(BONUS_NAME)

re: fclean all

rebonus: fclean bonus

.PHONY: all clean fclean re bonus rebonus