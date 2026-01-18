NAME = libft.a
CC = cc
CFLAGS = -Wall -Wextra -Werror -I.
SRC = 	ft_isalpha.c \
		ft_isdigit.c \
		ft_isalnum.c \
		ft_isascii.c \
		ft_isprint.c \
		ft_strlen.c \
		ft_strncmp \
		ft_strlcpy \
		ft_tolower \
		ft_toupper \
		ft_strlcat

OBJ = $(SRC:.c=.o)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

all: $(NAME)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)
clean:
	rm -f $(OBJ)
fclean: clean
	rm -f $(NAME)
re: all clean

.PHONY: all clean fclean re