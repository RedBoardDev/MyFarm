/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_click_items_inv.c
*/

#include "../../include/rpg.h"

static bool check_weapon(rpg_t *rpg)
{
    return (get_item_inv(rpg, I_CASE_MOVE) == SP_ITEM_SWORD ||
    get_item_inv(rpg, I_CASE_MOVE) == SP_ITEM_PICKAXE ||
    get_item_inv(rpg, I_CASE_MOVE) == SP_ITEM_SHOVEL ||
    get_item_inv(rpg, I_CASE_MOVE) == SP_FLASK_ATTACK ||
    get_item_inv(rpg, I_CASE_MOVE) == SP_FLASK_SPEED ||
    get_item_inv(rpg, I_CASE_MOVE) == SP_FLASK_DRUNK);
}

static int get_nearest_index_inventory(rpg_t *rpg)
{
    float nearest_distance = INFIN;
    int index = -1;
    float calc = 0;
    sfVector2f pos_mouse = {0, 0};
    sfVector2f pos_case = {0, 0};
    for (int i = 0; i < 11; ++i) {
        if (i == I_ATTACK && !check_weapon(rpg))
            ++i;
        if (i == I_ARMOR && get_item_inv(rpg, I_CASE_MOVE) != SP_ITEM_ARMOR)
            ++i;
        pos_mouse = rpg->all_events.mouse.pos_view;
        pos_case = rpg->player_stats.inventory.inventory_case[i].pos;
        calc = sqrt((SQUARE(pos_case.x - pos_mouse.x)) +
        (SQUARE(pos_case.y - pos_mouse.y)));
        if (calc < nearest_distance && get_item_inv(rpg, i) == -1) {
            nearest_distance = calc;
            index = i;
        }
    }
    return (index);
}

static void move_item_inventory(rpg_t *rpg, int i)
{
    int case_inv = -1;

    case_inv = check_if_in_inventory(rpg, i);
    if (case_inv != -1) {
        rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].
        item_spritesheet = i;
        rpg->player_stats.inventory.inventory_case[case_inv].
        item_spritesheet = -1;
    }
    rpg->spritesheet[i].pos = rpg->all_events.mouse.pos_view;
}

bool check_click_items_inventory(rpg_t *rpg, int i)
{
    sfFloatRect collision;

    if (rpg->spritesheet[i].clickable && rpg->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button_float(rpg->all_events.mouse.pos_view,
        collision)) {
            move_item_inventory(rpg, i);
            return (true);
        }
    }
    return (false);
}

void put_back_in_inventory(rpg_t *rpg)
{
    if (rpg->screen[SC_INVENTORY].active && rpg->all_events.mouse.left_released
    && rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet
    != -1) {
        rpg->player_stats.inventory.inventory_case
        [get_nearest_index_inventory(rpg)].item_spritesheet =
        rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].
        item_spritesheet;
        rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].
        item_spritesheet = -1;
    }
}
