##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile lib
##

SRC	=	arrays_utils.c	\
		is.c	\
		my_atoi.c	\
		my_getnbr.c	\
		my_itoa.c	\
		my_put_colors.c	\
		my_put_nbr.c	\
		my_putchar.c	\
		my_putstr.c	\
		my_revstr.c	\
		my_show_word_array.c	\
		my_str_to_word_array.c	\
		my_strcat.c	\
		my_strcmp.c	\
		my_strncpy.c	\
		my_strdup.c	\
		my_strlen.c	\
		my_strncat.c	\
		my_strncmp.c	\
		my_strcpy.c	\

OBJ	=	$(SRC:.c=.o)

NAME	=	libmy.a

all:	$(NAME)

$(NAME):	$(OBJ)
	cp my.h ../../include/
	ar rc libmy.a *.o
	cp *.a ..
	@echo -ne "\033[1;34m=============== Lib compilation ok ==============="
	@echo -e "\033[0m"

clean:
	rm -f $(OBJ)

fclean:	clean
	rm -f $(NAME)
	rm -f ../$(NAME)

re:	all fclean
