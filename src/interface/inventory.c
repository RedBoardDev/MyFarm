/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory.c
*/

#include "../../include/rpg.h"

extern int screen_inventory[];

void box_inventory(rpg_t *rpg)
{
    // int cursor_x = rpg->all_events.mouse.pos.x;
    // int cursor_y = rpg->all_events.mouse.pos.y;
    if (rpg->screen[SC_INVENTORY].active) {

    }
}

void toggle_inventory(rpg_t *rpg)
{
    bool status = rpg->screen[SC_INVENTORY].active;

    if (!rpg->screen[SC_MAIN_MAP].active)
        return;
    if (rpg->all_events.e) {
        rpg->all_events.e = false;
        rpg->screen[SC_INVENTORY].active = !status;
        toggle_spritesheet_scene(rpg, !status, screen_inventory, SC_INVENTORY);
    }
}

void manage_inventory(rpg_t *rpg)
{
    rpg->spritesheet[SP_INVENTORY].pos = rpg->begin.view.center;
    toggle_inventory(rpg);
    // box_inventory(rpg);
}
