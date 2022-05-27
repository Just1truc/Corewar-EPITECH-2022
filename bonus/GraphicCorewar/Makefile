##
## EPITECH PROJECT, 2022
## C_Project_Template
## File description:
## Makefile
##

SRC	=	main.c \
		$(wildcard src/*.c) \
		$(wildcard src/*/*.c) \

OBJ	=	$(SRC:.c=.o)

NAME	=	corewar

CFLAGS	=	-I./include -lncursesw -g3

.PHONY: all
all:	$(NAME)

$(NAME):	$(OBJ)
	gcc -o $(NAME) $(OBJ) $(CFLAGS)
	make clean

.PHONY: clean
clean:
	rm -f $(OBJ)
	rm -rf *.gcda
	rm -rf *.gcno

.PHONY: fclean
fclean:	clean
	rm -f $(NAME)

.PHONY:	re
re:	fclean all
