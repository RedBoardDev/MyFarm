/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory.c
*/

#include "../../include/rpg.h"

void box_inventory(rpg_t *rpg)
{
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
        toggle_spritesheet_scene(rpg, !status, SC_INVENTORY);
    }
}

void manage_inventory(rpg_t *rpg)
{
    toggle_inventory(rpg);
    if (rpg->screen[SC_INVENTORY].active) {
        rpg->player_stats.money = 1;
        rpg->spritesheet[SP_INVENTORY].pos = rpg->begin.view.center;
        sfText_setPosition(rpg->player_stats.inventory.money,
        (sfVector2f){rpg->spritesheet[SP_INVENTORY].pos.x - 130,
        rpg->spritesheet[SP_INVENTORY].pos.y + 102});
        sfText_setString(rpg->player_stats.inventory.money,
        my_itoa(rpg->player_stats.money));
    }
}
