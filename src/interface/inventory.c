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
    inventory->inventory_case[0].pos.x = pos_inv.x - 180 + 18;
    inventory->inventory_case[0].pos.y = pos_inv.y + 25 + 18;
    inventory->inventory_case[1].pos.x = pos_inv.x - 105 + 18;
    inventory->inventory_case[1].pos.y = pos_inv.y + 25 + 18;
    for (int i = 2, y = 0; y < 3; ++y) {
        for (int x = 0; x < 3; ++x, ++i) {
            inventory->inventory_case[i].pos.x = (pos_inv.x + 14) + 75 * x;
            inventory->inventory_case[i].pos.y = (pos_inv.y - 30) + 75 * y;
        }
    }
}

void manage_inventory(rpg_t *rpg)
{
    bool status = rpg->screen[SC_INVENTORY].active;

    if (!rpg->screen[SC_MAIN_MAP].active && !rpg->screen[SC_CEMETERY].active &&
    !rpg->screen[SC_GROTTE].active)
        return;
    box_inventory(rpg, &rpg->player_stats.inventory);
    if (rpg->all_events.e) {
        rpg->all_events.e = false;
        for (int i = SP_ITEM_SHOVEL; i <= SP_ITEM_BEETS; ++i)
            rpg->spritesheet[i].active = false;
        rpg->screen[SC_INVENTORY].active = !status;
        toggle_spritesheet_scene(rpg, !status, SC_INVENTORY);
    }
    if (rpg->screen[SC_INVENTORY].active) {
        rpg->spritesheet[SP_INVENTORY].pos = rpg->begin.view.center;
        sfText_setPosition(rpg->player_stats.inventory.money,
        (sfVector2f){rpg->spritesheet[SP_INVENTORY].pos.x - 80,
        rpg->spritesheet[SP_INVENTORY].pos.y + 98});
        sfText_setString(rpg->player_stats.inventory.money,
        my_itoa(rpg->player_stats.money));
    }
}

int check_if_in_inventory(rpg_t *rpg, int i)
{
    for (int a = 0; a < 11; ++a) {
        if (rpg->player_stats.inventory.inventory_case[a].item_spritesheet == i)
            return (a);
    }
    return (-1);
}

// static void print_inv(rpg_t *rpg)
// {
//     for (int a = 0; a < 11; ++a)
//         printf("%d ", rpg->player_stats.inventory.inventory_case[a].item_spritesheet);
//     printf("\n");
// }

void add_item_inventory(rpg_t *rpg, int item)
{
    if (check_if_in_inventory(rpg, item) != -1)
        return;
    for (int i = 2; i < 11; ++i)
        if (rpg->player_stats.inventory.inventory_case[i].item_spritesheet == -1) {
            rpg->player_stats.inventory.inventory_case[i].item_spritesheet = item;
            return;
        }
}
