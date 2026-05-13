CC = cc
NAME = push_swap

CFLAGS = -Wall -Wextra -Werror

FILES = ft_get_stack.c \
	ft_foreach_stack.c \
	ft_split.c \
	ft_strlcpy.c \
	ft_strlen.c \
	ft_strncmp.c \
	ft_strstr.c \
	ft_printf.c \
	ft_putstr.c \
	ft_putnbr.c \
	ft_putchar.c \
	ft_atoi.c \
	ft_isdigit.c \
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