##
## EPITECH PROJECT, 2018
## lemipc
## File description:
## Makefile
##

CC	=	gcc

NAME	=	lemipc

CFLAGS	=	-Iincludes -W -Wall -Wextra

SRC	=	src/check_error.c	\
		src/create_segment.c	\
		src/create_map.c	\
		src/player.c		\
		src/move_in_center.c	\
		src/surround.c		\
		src/winner.c		\
		src/utils_sem.c		\
		src/move_randomly.c	\
		src/wait_complet_team.c

SRC_MAIN=	src/main.c

SRC_T	=	tests/test_check_error.c	\
		tests/test_create_segment.c	\
		tests/test_create_map.c		\
		tests/test_utils_sem.c		\
		tests/test_add_player_in_map.c	\
		tests/test_move_in_center.c	\
		tests/test_winner.c		\
		tests/test_move_randomly.c	\
		tests/test_wait_complet_team.c

OBJ	=	$(SRC:.c=.o)		\
		$(SRC_MAIN:.c=.o)

RM	=	rm -f

all:	$(NAME)

$(NAME):	$(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(CFLAGS) $(LDFLAGS)

tests_run:	$(SRC_T)
	$(CC) $(SRC_T) $(SRC) $(CFLAGS) $(LDFLAGS) -o units --coverage -lcriterion -lgcov
	./units
	gcov *.gcno

clean:
	$(RM) $(OBJ)
	$(RM) *.gcda
	$(RM) *.gcno
	$(RM) *.gcov

fclean:	clean
	$(RM) $(NAME) units

re:	fclean all
