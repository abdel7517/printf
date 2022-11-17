SRC = ./ft_printf.c \
./ft_puts.c \
./ft_puts2.c

OBJ = $(SRC:.c=.o)

CFLAGS += -Wextra -Werror -Wall

NAME =	libftprintf.a

$(NAME): $(OBJ)
		 ar crs $(NAME) $(OBJ)

all:	$(NAME)

clean:
		rm -f $(OBJ)

fclean: clean
		rm -f $(NAME)

re:		fclean all

exec: all
	 gcc test/ft_printf.c -L. -lftprintf -o test/exec_test
	 ./test/exec_test