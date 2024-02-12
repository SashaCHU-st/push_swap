NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
SOURCES = free_stack.c \
			ft_split.c \
			helping_functions.c \
			input_checker.c \
			init_stack.c \
			main.c \
			process_arguments.c \
			push_swap_utils.c \
			push.c \
			reverse_from_first.c \
			reverse_from_last.c \
			sort.c \
			sorting_algo.c \
			swap.c \
			three_sorting.c 
			
OBJ = ${SOURCES:.c=.o}

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(NAME)

%.o:%.c
	$(CC) $(CFLAGS) -c $^ -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -f $(NAME)

re: fclean all

.PHONY: all clean fclean re