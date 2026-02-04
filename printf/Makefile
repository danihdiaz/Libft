NAME = libftprintf.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I. -Ilibft
SRC = ft_printf.c \
	ft_printchar.c \
	ft_printstr.c \
	ft_printvoid.c \
	ft_putchar.c \
	ft_puthex.c

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	make -C libft
	cp libft/libft.a $(NAME)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)
	make -C libft clean

fclean: clean
	rm -f $(NAME)
	make -C libft fclean

re: fclean all

.PHONY: all clean fclean re