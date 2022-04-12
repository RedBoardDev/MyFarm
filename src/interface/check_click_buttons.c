/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_click_buttons.c
*/

#include "../../include/rpg.h"

static void nothing(rpg_t *rpg)
{
    return;
}

void back_button(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SP; ++i)
        rpg->spritesheet[i].active = false;
    toggle_spritesheet_scene(rpg, true, rpg->old_screen, -1);
}

static bool check_click_one_button(rpg_t *rpg, int i)
{
    static void (*functions[])(rpg_t *) = FUNCTIONS_BUTTONS;
    sfFloatRect collision;

    if (rpg->spritesheet[i].clickable && rpg->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button_float(rpg->all_events.mouse.pos_view, collision)) {
            (*functions[i])(rpg);
            rpg->all_events.mouse.left = false;
            return (true);
        }
    }
    return (false);
}

void check_click_buttons(rpg_t *rpg)
{
    if (!rpg->all_events.mouse.left_released)
        return;
    for (int i = 0; i < NBR_SP; ++i)
        if (check_click_one_button(rpg, i))
            return;
}
