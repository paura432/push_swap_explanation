NAME = push_swap

MY_SOURCES = push_swap.c listas.c checker/check_errors.c moves/moves_sp.c moves/moves_r.c moves/moves_rr.c \
				algorithm/algorithm.c algorithm/algorithm_a2b.c algorithm/algorithm_b2a.c algorithm/nums_control.c


MY_OBJECTS = $(MY_SOURCES:.c=.o)

CC = gcc
CFLAGS = -Wall -Wextra -Werror -Ilibreria #-g3 -fsanitize=address

all: ${NAME}
${NAME}: ${MY_OBJECTS}
	@${MAKE} -C ./Libft
	@${CC} ${CFLAGS} ${MY_OBJECTS} ./Libft/libft.a -o ${NAME}

clean:
		@${MAKE} -C ./libft fclean
		rm -f $(MY_OBJECTS)

fclean: clean
		rm -f $(NAME)

re:		fclean all

valgrind_check: ${NAME}
	valgrind --leak-check=full

.PHONY: all, clean, fclean, re
