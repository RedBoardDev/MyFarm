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
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, nothing, nothing,  \
    launch_game, quit_game, nothing, nothing}
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
    SP_PLAYER,
    SP_PLAY,
    SP_QUIT,
    SP_CUSTOM,
    NBR_SP
};

enum screens {
    SC_MENU,
    SC_MAIN_MAP,
    SC_BASE,
    // SC_CUSTOM_PLAYER,
    // SC_JAIL,
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

#endif
