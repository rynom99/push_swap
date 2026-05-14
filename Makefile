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
	ft_putchar.c \
	ft_atoi.c \
	ft_isdigit.c \
	ft_disorder.c \
	ft_set_ranks.c \
	push.c \
	swap.c \
	rotate.c \
	algor0.c\
	agor1.c \
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

debug: fclean
	rm -f debug
	$(CC) $(CFLAGS) -I. $(FILES) -o debug -g

unit_test: fclean
	rm -f debug
	cc -Wall -Wextra -Werror -I. ft_get_stack.c ft_get_stack_ref.c ft_foreach_stack.c ft_split.c ft_strlcpy.c ft_strlen.c ft_strcmp.c ft_printf.c ft_putstr.c ft_putnbr.c ft_putchar.c ft_atoi.c ft_isdigit.c ft_disorder.c ft_set_ranks.c push.c swap.c rotate.c unit_test.c -o debug -g

.PHONY: all clean fclean re