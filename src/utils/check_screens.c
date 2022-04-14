/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_screens.c
*/

#include "../../include/rpg.h"

bool is_in_menu(rpg_t *rpg)
{
    return (rpg->screen[SC_MENU].active || rpg->screen[SC_CUSTOM_SKINS].active
    || rpg->screen[SC_HOW_PLAY].active);
}

bool is_in_gameplay(rpg_t *rpg)
{
    return (rpg->screen[SC_MAIN_MAP].active || rpg->screen[SC_BASE].active
    || rpg->screen[SC_GROTTE].active || rpg->screen[SC_INVENTORY].active);
}
