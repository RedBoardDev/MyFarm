/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_mouse_on_buttons.c
*/

#include "../../include/rpg.h"

bool check_mouse_on_one_button_int(sfVector2i pos, sfFloatRect collision)
{
    if (pos.x > collision.left &&
    pos.x < collision.left + collision.width &&
    pos.y > collision.top &&
    pos.y < collision.top + collision.height)
        return (true);
    else
        return (false);
}

bool check_mouse_on_one_button_float(sfVector2f pos, sfFloatRect collision)
{
    if (pos.x > collision.left &&
    pos.x < collision.left + collision.width &&
    pos.y > collision.top &&
    pos.y < collision.top + collision.height)
        return (true);
    else
        return (false);
}

void check_one_button(rpg_t *rpg, int i)
{
    sfFloatRect collision;

    if (rpg->spritesheet[i].active && rpg->spritesheet[i].clickable &&
    rpg->spritesheet[i].change_sprite_on_mouse) {
        collision = sfSprite_getGlobalBounds(rpg->spritesheet[i].sprite);
        if (check_mouse_on_one_button_float(rpg->all_events.mouse.pos_view,
        collision)) {
            rpg->spritesheet[i].rect.top = (rpg->all_events.mouse.left) ?
            rpg->spritesheet[i].rect.height * 2 :
            rpg->spritesheet[i].rect.height;
        } else
            rpg->spritesheet[i].rect.top = 0;
    }
}

void check_mouse_on_all_buttons(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SP; ++i)
        check_one_button(rpg, i);
}
