/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_soundbar.c
*/

#include "../../../include/rpg.h"

int check_click_soundbox(rpg_t *rpg)
{
    sfFloatRect collision_music =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_SOUND_SLIDER_MUSIC].sprite);

    sfFloatRect collision_effect =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_SOUND_SLIDER_EFFECT].sprite);

    if (check_mouse_on_one_button_int(rpg->all_events.mouse.pos,
    collision_music)) {
        rpg->all_events.mouse.left = false;
        return (SP_SOUND_SLIDER_MUSIC);
    } else if (check_mouse_on_one_button_int(rpg->all_events.mouse.pos,
    collision_effect)) {
        rpg->all_events.mouse.left = false;
        return (SP_SOUND_SLIDER_EFFECT);
    }
    return (0);
}
