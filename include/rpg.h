/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.h
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include "my.h"
    #include "protos.h"
    #include "struct.h"
    #include "enum.h"
    #define RADIAN(x) x * 3.14159265359 / 180
    #define FUNCTIONS_BUTTONS { \
    nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, button_bed_saving, \
    open_big_maps, nothing, shop_button1, shop_button2, shop_button3, \
    shop_button4, how_play, nothing, put_shop_gui, nothing, nothing, nothing,  \
    skin_blue, skin_brown, skin_cyan, skin_green, skin_grey, skin_pink, \
    skin_red, skin_yellow, nothing, nothing, nothing, launch_begin_cutscene, \
    quit_game, display_custom_skins, button_option_main_menu, back_button, \
    button_next_grotte, nothing, nothing, nothing, \
    button_toggle_sound_effect, nothing, nothing, nothing, \
    button_toggle_sound_music, nothing, nothing, button_left_fps,  \
    button_right_fps, nothing,  button_toggle_fullscreen, \
    button_toggle_dark_mode, button_toggle_show_fps, nothing, nothing, \
    nothing, nothing, nothing, click_item_prisoner_pee, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    button_resume_game, button_option_game, button_leave_game, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing \
    }
    #define SPAWN_X WIDTH / 2
    #define SPAWN_Y WIDTH / 2 + 80
    #define SPEED_PLAYER 1.5
    #define SECOND_TO_MICRO(x) x * 1000000
    #define SQUARE(x) (x) * (x)

#endif
