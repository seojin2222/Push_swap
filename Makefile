NAME = push_swap

CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS = main.c \
	init_ps.c \
	is_sorted.c \
	parse_utils.c \
	ft_split.c \
	count_total_numbers.c \
	sort_stack.c \
	sort_chunk.c \
	stack_ops.c \
	stack_ops2.c \
	stack_ops3.c

OBJS = $(SRCS:.c=.o)

HEADER = push_swap.h

all: $(NAME)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -f $(OBJS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re