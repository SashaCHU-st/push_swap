NAME = push_swap.a
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = push_swap_utils.c \
			push.c \
			reverse_from_first.c \
			reverse_from_last.c \
			swap.c \
			main.c \
			three_sorting.c \
			sort.c \
			

	

OBJ = ${SOURCES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	ar rc $(NAME) $(OBJ)
	ranlib $(NAME)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re