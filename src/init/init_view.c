/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_view.c
*/

#include "../../include/rpg.h"

void init_view(rpg_t *rpg)
{
    rpg->begin.view.view =
    sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}
