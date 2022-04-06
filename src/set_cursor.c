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
