CC = cc
NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

FILES = ft_get_stack.c \
	ft_get_stack_ref.c \
	ft_foreach_stack.c \
	ft_split.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strcmp.c \
	ft_printf.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_fd.c \
	ft_putchar.c \
	ft_str_to_int32.c \
	ft_arr_len.c \
	ft_array_ops.c \
	ft_isdigit.c \
	ft_disorder.c \
	ft_set_ranks.c \
	ft_log.c \
	stack.c \
	push.c \
	swap.c \
	rotate.c \
	reverse_rotate.c \
	simple_algorithm.c \
	medium_algorithm.c \
	complex_algorithm.c \
	dumb_algorithm.c \
	ft_push_swap_helper.c \
	ft_push_swap_logger.c \
	main.c

OBJECTS = $(FILES:.c=.o)

all: $(NAME)

$(NAME): $(OBJECTS)
	$(CC) $(OBJECTS) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -I. -c $< -o $@

clean:
	rm -f $(OBJECTS)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re