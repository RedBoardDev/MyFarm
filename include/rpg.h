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
    #define RADIAN(x) x * 3.14159265359 / 180
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, nothing, nothing, nothing, \
    skin_blue, skin_brown, skin_cyan, skin_green, skin_grey, skin_pink, \
    skin_red, skin_yellow, nothing, nothing, nothing, launch_game, quit_game, display_custom_skins,    \
    nothing}
    #define SPAWN_X WIDTH / 2
    #define SPAWN_Y WIDTH / 2 + 80

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

enum sprites {
    SP_BACKGROUND_SC_MAIN_MAP,
    SP_BACKGROUND_SC_MENU,
    SP_BACKGROUND_SC_BASE,
    SP_BACKGROUND_JAIL,
    SP_BACKGROUND_GROTTE,
    SP_PLAYER,
    SP_PLAYER_BLUE,
    SP_PLAYER_BROWN,
    SP_PLAYER_CYAN,
    SP_PLAYER_GREEN,
    SP_PLAYER_GREY,
    SP_PLAYER_PINK,
    SP_PLAYER_RED,
    SP_PLAYER_YELLOW,
    SP_SOUND_CLICK,
    SP_SOUND_POTENTIO,
    SP_SOUND_SELECT,
    SP_PLAY,
    SP_QUIT,
    SP_CUSTOM,
    SP_INVENTORY,
    SP_LIFE_BAR_BOX,
    SP_LIFE_BAR,
    NBR_SP
};

enum screens {
    SC_MENU,
    SC_CUSTOM_SKINS,
    SC_MAIN_MAP,
    SC_BASE,
    SC_GROTTE,
    // SC_CUSTOM_PLAYER,
    // SC_JAIL,
    SC_INVENTORY,
    NBR_SCREENS
};

enum bleu_maisons {
    B_BASE = 100,
    B_JAIL,
    B_TENTE,
    B_GROTTE,
    B_TAVERNE
};

enum sounds {
    SOUND_MENU,
    SOUND_WALK,
    SOUND_DOOR,
    NBR_SOUND,
};

enum utilitaire {
    SELECTED_PLAYER = -10,
    CURSOR,
};

#endif
