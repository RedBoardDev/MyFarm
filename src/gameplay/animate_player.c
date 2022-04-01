/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_player.c
*/

#include "../../include/rpg.h"

void animate_player(rpg_t *rpg)
{
    sfColor color = get_color_from_player(rpg->imgs_colors.main_map,
    rpg->spritesheet[rpg->skin].pos);
    float time_player =
    sfClock_getElapsedTime(rpg->spritesheet[rpg->skin].clock).microseconds;

    if (!rpg->all_events.down && !rpg->all_events.up && !rpg->all_events.left
    && !rpg->all_events.right && !rpg->all_events.s && !rpg->all_events.z
    && !rpg->all_events.q && !rpg->all_events.d)
        rpg->spritesheet[rpg->skin].rect.left = 0;
    else if (time_player >= 200000) {
        rpg->spritesheet[rpg->skin].rect.left += 48;
        if (rpg->all_events.down || rpg->all_events.s)
            rpg->spritesheet[rpg->skin].rect.top = 0;
        if (rpg->all_events.up || rpg->all_events.z)
            rpg->spritesheet[rpg->skin].rect.top = 64 * 3;
        if (rpg->all_events.left || rpg->all_events.q)
            rpg->spritesheet[rpg->skin].rect.top = 64 * 1;
        if (rpg->all_events.right || rpg->all_events.d)
            rpg->spritesheet[rpg->skin].rect.top = 64 * 2;
        if (rpg->spritesheet[rpg->skin].rect.left >= 192)
            rpg->spritesheet[rpg->skin].rect.left = 0;
        sfClock_restart(rpg->spritesheet[rpg->skin].clock);
        play_sound(rpg->sound.sound_list[SOUND_WALK].sound, rpg->sound.volume);
    }
    if (!rpg->screen[SC_MAIN_MAP].active)
        return;
    if (color.g == 255 && rpg->spritesheet[rpg->skin].rect.top < 256)
        rpg->spritesheet[rpg->skin].rect.top += 256;
    else if (color.g != 255 && rpg->spritesheet[rpg->skin].rect.top >= 256)
        rpg->spritesheet[rpg->skin].rect.top -= 256;
}
