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
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, launch_game,  \
    nothing, nothing, nothing}

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

enum sprites {
    S_BACKGROUND_MAIN_MAP,
    S_BACKGROUND_MENU,
    S_PLAYER,
    B_PLAY,
    B_QUIT,
    B_CUSTOM,
    NBR_SPRITE
};

enum screens {
    MENU,
    GAME,
    CUSTOM_PLAYER,
    NBR_SCREENS
};

#endif
