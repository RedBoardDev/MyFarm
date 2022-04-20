/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** mouse.c
*/

#include "../include/rpg.h"

void toggle_cursor(sfRenderWindow *window, bool status)
{
    sfRenderWindow_setMouseCursorVisible(window, status);
}

void set_size_cursor(rpg_t *rpg, float size)
{
    sfSprite_setScale(rpg->spritesheet[SP_CURSOR].sprite,
    (sfVector2f){size, size});
}
