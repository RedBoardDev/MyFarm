/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_soundbar.c
*/

#include "../../../include/rpg.h"

void check_click_soundbox(rpg_t *rpg)
{
    sfFloatRect collision =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_SOUNDBAR].sprite);

    rpg->sound.volume_active = true;
    collision.width = collision.height;
    if (check_mouse_on_one_button_int(rpg->all_events.mouse.pos, collision)) {
        if (rpg->sound.volume) {
            rpg->sound.volume_backup = rpg->sound.volume;
            rpg->sound.volume = 0;
            rpg->spritesheet[SP_SOUND_SLIDER].pos.x = WIDTH - 380;
        } else {
            rpg->sound.volume = rpg->sound.volume_backup;
            rpg->spritesheet[SP_SOUND_SLIDER].pos.x =
            (WIDTH - 380) + (rpg->sound.volume * 2.6);
        }
        rpg->all_events.mouse.left = false;
    }
}
