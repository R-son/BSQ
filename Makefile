##
## EPITECH PROJECT, 2018
## 101pong
## File description:
## Compilation Makefile
##

SRC	=	main.c

RM	=	rm -f

OBJ	=	$(SRC:.c=.o)

NAME	=	./bsq

LIB     =       lib/my/libmy.a

CFLAGS	=	-I include

all:	$(NAME)

$(NAME):	$(OBJ)
	make -C ./lib/my/
	gcc -o $(NAME) main.c $(LIB)

clean:
	rm -f $(OBJ)

fclean: clean
	rm -f $(NAME)
	rm -rf *.o
	rm -rf *~
	rm -rf *#
	rm -rf lib/my/libmy.a
	rm -rf lib/my/*.o
	rm -rf lib/my/*~
	rm -rf lib/my/*#
	rm -rf include/*~
	rm -rf include/*#

re:	fclean all

.PHONY: all clean fclean re
