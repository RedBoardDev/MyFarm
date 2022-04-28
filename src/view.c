/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** view.c
*/

#include "../include/rpg.h"

void set_view(rpg_t *rpg, sfVector2f view_pos)
{
    rpg->begin.view.center = view_pos;
    sfView_setCenter(rpg->begin.view.view, view_pos);
    sfRenderWindow_setView(rpg->begin.window, rpg->begin.view.view);
}
