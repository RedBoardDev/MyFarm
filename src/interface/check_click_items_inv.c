/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_click_items_inv.c
*/

#include "../../include/rpg.h"

static int get_nearest_index_inventory(rpg_t *rpg)
{
    float nearest_distance = INFIN;
    int index = -1;
    float calc = 0;
    sfVector2f pos_mouse = {0, 0};
    sfVector2f pos_case = {0, 0};

    for (int i = 0; i < 11; ++i) {
        pos_mouse = rpg->all_events.mouse.pos_view;
        pos_case = rpg->player_stats.inventory.inventory_case[i].pos;
        calc = sqrt((SQUARE(pos_case.x - pos_mouse.x)) + (SQUARE(pos_case.y - pos_mouse.y)));
        if (calc < nearest_distance && rpg->player_stats.inventory.inventory_case[i].item_spritesheet == -1) {
            nearest_distance = calc;
            index = i;
        }
    }
    return (index);
}

bool check_click_items_inventory(rpg_t *rpg, int i)
{
    sfFloatRect collision;
    int case_inv = -1;

    if (rpg->spritesheet[i].clickable && rpg->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button_float(rpg->all_events.mouse.pos_view,
        collision)) {
            case_inv = check_if_in_inventory(rpg, i);
            if (case_inv != -1) {
                rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet = i;
                rpg->player_stats.inventory.inventory_case[case_inv].item_spritesheet = -1;
            }
            rpg->spritesheet[i].pos = rpg->all_events.mouse.pos_view;
            return (true);
        }
    }
    return (false);
}

void put_back_in_inventory(rpg_t *rpg)
{
    if (rpg->screen[SC_INVENTORY].active && rpg->all_events.mouse.left_released
    && rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet != -1) {
        rpg->player_stats.inventory.inventory_case
        [get_nearest_index_inventory(rpg)].item_spritesheet =
        rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet;
        rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet = -1;
    }
}
