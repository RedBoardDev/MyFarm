/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** inventory.c
*/

#include "../../include/rpg.h"

static void box_inventory(rpg_t *rpg, inventory_t *inventory)
{
    sfVector2f pos_inv = rpg->spritesheet[SP_INVENTORY].pos;
    if (!rpg->screen[SC_INVENTORY].active)
        return;
    inventory->inventory_case[0].pos.x = pos_inv.x - 170;
    inventory->inventory_case[0].pos.y = pos_inv.y + 25;
    inventory->inventory_case[1].pos.x = pos_inv.x - 105;
    inventory->inventory_case[1].pos.y = pos_inv.y + 25;

    for (int i = 2, y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x, ++i) {
            inventory->inventory_case[i].pos.x = (pos_inv.x + 22) + 72 * x;
            inventory->inventory_case[i].pos.y = (pos_inv.y - 30) + 72 * y;
        }
    }
}

void toggle_inventory(rpg_t *rpg)
{
    bool status = rpg->screen[SC_INVENTORY].active;

    if (!rpg->screen[SC_MAIN_MAP].active)
        return;
    box_inventory(rpg, &rpg->player_stats.inventory);
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
