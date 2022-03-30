/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** check_click_buttons.c
*/

#include "../../include/rpg.h"

void nothing(rpg_t *rpg)
{
    return;
}

bool check_click_one_button(rpg_t *rpg, int i)
{
    static const void (*functions[])(rpg_t *) = FUNCTIONS_BUTTONS;
    sfFloatRect collision;

    if (rpg->spritesheet[i].clickable && rpg->spritesheet[i].active) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button(rpg->all_events.mouse.pos, collision)) {
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
    for (int i = 0; i < NBR_SPRITE; ++i)
        if (check_click_one_button(rpg, i))
            return;
}
