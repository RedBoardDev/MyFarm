/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_click_buttons.c
*/

#include "../../include/rpg.h"

static void nothing(rpg_t *rpg)
{
    rpg->all_events.ctrl = rpg->all_events.ctrl;
    return;
}

void back_button(rpg_t *rpg)
{
    sfColor c = {255, 255, 255, 255};

    for (int i = 0; i < NBR_SP; ++i)
        rpg->spritesheet[i].active = false;
    for (int i = 0; i < NBR_SC; ++i)
        rpg->screen[i].active = false;
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_SC_MENU].sprite, c);
    toggle_spritesheet_scene(rpg, true, rpg->index_old_s);
    set_view(rpg, rpg->screen[rpg->index_old_s].view_pos);
}

static bool check_click_one_button(rpg_t *rpg, int i)
{
    static void (*functions[])(rpg_t *) = FUNCTIONS_BUTTONS;
    sfFloatRect collision;

    if (rpg->spritesheet[i].clickable && rpg->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button_float(rpg->all_events.mouse.pos_view,
        collision)) {
            (*functions[i])(rpg);
            rpg->all_events.mouse.left = false;
            return (true);
        }
    }
    return (false);
}

void check_click_buttons(rpg_t *rpg)
{
    put_back_in_inventory(rpg);
    if (rpg->player_stats.inventory.inventory_case[I_CASE_MOVE].item_spritesheet
    != -1) {
        check_click_items_inventory(rpg, rpg->player_stats.inventory.
        inventory_case[11].item_spritesheet);
        return;
    }
    for (int i = SP_ITEM_SHOVEL; rpg->all_events.mouse.left &&
    i <= SP_FLASK_REVIVE; ++i)
        if (check_click_items_inventory(rpg, i))
            return;
    if (!rpg->all_events.mouse.left_released)
        return;
    for (int i = 0; i < NBR_SP; ++i)
        if (check_click_one_button(rpg, i))
            return;
}
