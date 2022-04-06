/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory.c
*/

#include "../../include/rpg.h"

extern int screen_inventory[];

void toggle_inventory(rpg_t *rpg)
{
    bool status = rpg->screen[SC_INVENTORY].active;

    if (!rpg->screen[SC_MAIN_MAP].active)
        return;
    if (rpg->all_events.e) {
        rpg->all_events.e = false;
        rpg->screen[SC_INVENTORY].active = !status;
        toggle_spritesheet_scene(rpg, status, screen_inventory, rpg->spritesheet);
    }
    rpg->spritesheet[SP_INVENTORY].pos = rpg->begin.view.center;

}
