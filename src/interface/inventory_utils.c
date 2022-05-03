/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** inventory_utils.c
*/

#include "../../include/rpg.h"

int check_if_in_inventory(rpg_t *rpg, int i)
{
    for (int a = 0; a < 11; ++a) {
        if (rpg->player_stats.inventory.inventory_case[a].item_spritesheet == i)
            return (a);
    }
    return (-1);
}

void add_item_inventory(rpg_t *rpg, int item)
{
    if (check_if_in_inventory(rpg, item) != -1)
        return;
    for (int i = 2; i < 11; ++i)
        if (rpg->player_stats.inventory.inventory_case[i].item_spritesheet ==
        -1) {
            rpg->player_stats.inventory.inventory_case[i].item_spritesheet =
            item;
            return;
        }
}

int remove_item_inventory(rpg_t *rpg, int item)
{
    if (check_if_in_inventory(rpg, item) == -1)
        return (84);
    for (int i = 0; i < 11; ++i)
        if (rpg->player_stats.inventory.inventory_case[i].item_spritesheet ==
        item) {
            rpg->player_stats.inventory.inventory_case[i].item_spritesheet = -1;
            return (0);
        }
    return (0);
}

int get_item_inv(rpg_t *rpg, int case_i)
{
    if (case_i < 0 || case_i > 11)
        return (-1);
    return (rpg->player_stats.inventory.
    inventory_case[case_i].item_spritesheet);
}
