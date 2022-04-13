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
				events/mouse	\
				gameplay/animate_player	\
				gameplay/animate_boss	\
				gameplay/move_all	\
				gameplay/move_player_and_view	\
				gameplay/teleport_player	\
				gameplay/quests/q_soldiers	\
				gameplay/utils	\
				init/init_all	\
				init/init_imgs	\
				init/init_main_map	\
				init/init_screens	\
				init/init_sounds	\
				spritesheets/init_spritesheets_boss	\
				spritesheets/init_spritesheets_menu	\
				spritesheets/init_spritesheets_npc	\
				spritesheets/init_spritesheets_player	\
				spritesheets/init_spritesheets_rooms	\
				spritesheets/init_spritesheets	\
				spritesheets/init_spritesheets_item	\
				init/init_view	\
				interface/functions_pointers/button_menu	\
				interface/functions_pointers/choose_skin1	\
				interface/functions_pointers/choose_skin2	\
				interface/check_click_buttons	\
				interface/check_mouse_on_buttons	\
				interface/inventory	\
				spritesheets/utils_sprites	\
				utils/check_screens	\
				utils/utils_draw	\
				utils/utils_csfml	\
				utils/utils	\
				clean_window	\
				destroy_all	\
				die	\
				draw_all	\
				execute_all	\
				lib_sound	\
				main	\
				myrpg	\
				set_cursor	\
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

CFLAGS	+=	-Werror	\
			-Wextra	\
			-Wall	\

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
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS) $(CFLAGS)
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
