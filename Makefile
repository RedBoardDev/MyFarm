##
## EPITECH PROJECT, 2021
## project
## File description:
## Makefile
##

NAME	=	my_rpg

# src
SRC_DIR	=	src/
EXTENSION	=	.c

SRC_FILES	=	events/events	\
				events/key_pressed	\
				events/key_released	\
				interface/utils_sprites	\
				interface/init_main_map	\
				interface/init_spritesheets	\
				events/mouse	\
				clean_window	\
				draw_simple	\
				init_all	\
				lib_sound	\
				main	\
				move_all	\
				utils	\
				myrpg	\
				view	\

SRC	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), $(SRC_FILES)))

# no main
SRC_FILES_NO_MAIN	=	$(filter-out main, $(SRC_FILES))

SRC_NO_MAIN	=	$(addprefix $(SRC_DIR), $(addsuffix $(EXTENSION), \
$(SRC_FILES_NO_MAIN)))

# tests
TESTS_DIR	=	tests/

TESTS_FILES	=	tests.c	\

TESTS	=	$(addprefix $(TESTS_DIR), $(TESTS_FILES))

NAME_TESTS	=	unit_tests

# compil
OBJ	=	$(SRC:.c=.o)

CC	=	gcc -g

# clean
BIN	=	vgcore*	\
		unit_tests*	\

# flags
FLAGS	=	-I./include	\
		-L./lib	\
		-lmy	\
		-g	\

WFLAGS	=	-Wall	\
			-Werror	\
			-Wextra	\

CSFML_FLAGS	=	-lcsfml-graphics	\
			-lcsfml-window	\
			-lcsfml-system	\
			-lcsfml-audio	\
			-lm

TESTS_FLAGS	=	--coverage	\
				-lcriterion

all:	$(NAME)

$(NAME):	$(OBJ)
	@echo -e "\033[1;34m\n============== Files compilation ok =============="
	@echo -e "\033[0m"
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS)
	@echo -e "\033[1;32m\n================= Compilation done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean
	@echo -e "\033[1;33m\n=============== Cleaning done ==============="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean
	@echo -e "\033[1;33m\n=============== Full cleaning done ==============="
	@echo -e "\033[0m"

re:	fclean all

exec:	re
	@echo
	@echo "-------------------------------------------------"
	@echo
	@./$(NAME)

gcovr:
		gcovr --exclude tests
		gcovr --exclude tests --branches

tests_run:	fclean
		make -C lib/my
		gcc -o $(NAME_TESTS) $(SRC_NO_MAIN) $(TESTS) $(TESTS_FLAGS) $(FLAGS)
		./$(NAME_TESTS)

.PHONY:		all clean fclean re exec gcovr tests_run
