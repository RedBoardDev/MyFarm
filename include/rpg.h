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
    #include "spritesheet.h"
    #include "struct.h"
    #define RADIAN(x) x * 3.14159265359 / 180
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, nothing, nothing,  \
    launch_game, quit_game, nothing, nothing}

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

enum sprites {
    S_BACKGROUND_MAIN_MAP,
    S_BACKGROUND_MENU,
    S_BACKGROUND_BASE,
    S_BACKGROUND_JAIL,
    S_PLAYER,
    B_PLAY,
    B_QUIT,
    B_CUSTOM,
    NBR_SPRITE
};

enum screens {
    MENU,
    GAME,
    BASE,
    // CUSTOM_PLAYER,
    // JAIL,
    NBR_SCREENS
};

enum maisons {
    M_BASE = 100,
    M_JAIL,
    // M_TENTE,
    // M_GROTTE,
    // M_TAVERNE
};

#endif
