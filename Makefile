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

SRC_FILES	=	cutscenes/init_spritesheet_cutscenes	\
				cutscenes/move_player_cutscene	\
				cutscenes/cutscenes_begin	\
				cutscenes/cutscenes_final	\
				cutscenes/utils_cutscenes	\
				events/events	\
				events/key_pressed	\
				events/key_released	\
				events/mouse	\
				execute/execute_all	\
				execute/execute_bosses	\
				execute/execute_gameplay	\
				execute/execute_menus	\
				gameplay/boss/animations_executioner	\
				gameplay/boss/animations_golem	\
				gameplay/boss/attack_player_hoe	\
				gameplay/boss/check_rush_to_player	\
				gameplay/boss/ia_executioner	\
				gameplay/boss/ia_golem	\
				gameplay/boss/move_bosses	\
				gameplay/animate_player	\
				gameplay/animate_selected_skin	\
				gameplay/collisions_npc	\
				gameplay/collisions	\
				gameplay/minimap	\
				gameplay/move_all	\
				gameplay/move_player_and_view_h_v	\
				gameplay/move_player_and_view	\
				gameplay/move_player_get_speed	\
				gameplay/teleport_player_house	\
				gameplay/teleport_player	\
				gameplay/quests/utils_quest	\
				gameplay/quests/quest_dialog	\
				gameplay/quests/quetes_inv	\
				gameplay/utils	\
				init/init_all	\
				init/init_events	\
				init/init_imgs	\
				init/init_main_map	\
				init/init_other	\
				init/init_quests	\
				init/init_screens	\
				init/init_sounds	\
				init/init_inventory	\
				spritesheets/init_spritesheets_boss	\
				spritesheets/init_spritesheets_menu	\
				spritesheets/init_spritesheets_npc	\
				spritesheets/init_spritesheets_player	\
				spritesheets/init_spritesheets_quests	\
				spritesheets/init_spritesheets_rooms	\
				spritesheets/init_spritesheets	\
				spritesheets/init_spritesheets_item	\
				spritesheets/init_sprites_menu_options	\
				spritesheets/utils_sprites	\
				init/init_view	\
				interface/functions_pointers/button_menu	\
				interface/functions_pointers/button_menu_options	\
				interface/functions_pointers/buttons_boss	\
				interface/functions_pointers/buttons_toggle_params	\
				interface/functions_pointers/choose_skin1	\
				interface/functions_pointers/choose_skin2	\
				interface/functions_pointers/button_soundbar	\
				interface/functions_pointers/button_house	\
				interface/functions_pointers/gui_shop	\
				interface/functions_pointers/launch_function	\
				interface/functions_pointers/button_item	\
				interface/check_click_buttons	\
				interface/check_click_items_inv	\
				interface/check_mouse_on_buttons	\
				interface/inventory_utils	\
				interface/inventory	\
				interface/menu_pause	\
				save_function/open_file_stats	\
				save_function/open_file	\
				save_function/save_progress_stats	\
				save_function/save_progress	\
				utils/check_screens	\
				utils/utils_draw	\
				utils/utils_zoom	\
				utils/utils_csfml	\
				utils/utils_skills	\
				utils/utils_skills2	\
				utils/utils	\
				clean_window	\
				destroy_all	\
				die	\
				draw_all	\
				drunk	\
				fps	\
				lib_sound	\
				lib_text	\
				main	\
				myrpg	\
				notif	\
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
	@echo -ne "\033[1;34m=============== Files compilation ok ============="
	@echo -e "\033[0m"
	make -C lib/my
	$(CC) -o $(NAME) $(OBJ) $(FLAGS) $(CSFML_FLAGS) $(CFLAGS)
	@echo -ne "\033[1;32m=============== Compilation done ================="
	@echo -e "\033[0m"

clean:
	rm -f $(BIN)
	rm -f $(OBJ)
	make -C lib/my clean
	@echo -ne "\033[1;33m=============== Cleaning done ===================="
	@echo -e "\033[0m"

fclean:	clean
	rm -f $(NAME)
	make -C lib/my fclean
	@echo -ne "\033[1;33m=============== Full cleaning done ==============="
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
