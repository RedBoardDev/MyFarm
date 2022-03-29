/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** view.c
*/

#include "../include/rpg.h"

void set_view(rpg_t *rpg)
{
    sfView_setCenter(rpg->begin.view.view, (sfVector2f){rpg->begin.view.center.x, rpg->begin.view.center.y});
    sfRenderWindow_setView(rpg->begin.window, rpg->begin.view.view);
}
