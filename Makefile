NAME = libftprintf.a

FLAGS = -Wall -Wextra -Werror

SRC = ft_printf.c \
				utils_printf.c \
				utils2_printf.c \
				write_char.c \
				write_hex.c \
				write_adress.c \
				write_string.c \
				write_int.c \
				utils_print_nbrs.c \
				utils_print_nbrs2.c

OBJ = $(SRC:.c=.o)

all: $(NAME)

$(OBJ): $(SRC)
	gcc $(FLAGS) -c $(SRC)

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME) $(OBJ)

re: fclean all

.PHONY: all clean fclean re