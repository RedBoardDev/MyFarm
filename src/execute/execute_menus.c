/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_menus.c
*/

#include "../../include/rpg.h"

void execute_all_menus(rpg_t *rpg)
{
    set_size_cursor(rpg, 0.15);
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}
