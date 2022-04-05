/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** mouse.c
*/

#include "../include/rpg.h"

void hide_cursor(sfRenderWindow *window)
{
    sfRenderWindow_setMouseCursorVisible(window, true);
}

void show_cursor(sfRenderWindow *window)
{
    sfRenderWindow_setMouseCursorVisible(window, false);
}
