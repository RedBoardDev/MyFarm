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

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

enum sprites {
    S_BACKGROUND_MAIN_MAP,
    S_PLAYER,
    NBR_SPRITE
};

#endif
