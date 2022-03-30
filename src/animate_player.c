/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_player.c
*/

#include "../include/rpg.h"

void animate_player(rpg_t *rpg)
{
    sfColor color = get_color_from_player(rpg->map_colors,
    rpg->spritesheet[S_PLAYER].pos);
    float time_player = sfClock_getElapsedTime(rpg->spritesheet[S_PLAYER].clock).microseconds;

    if (!rpg->all_events.down && !rpg->all_events.up && !rpg->all_events.left
    && !rpg->all_events.right)
        rpg->spritesheet[S_PLAYER].rect.left = 0;
    else if (time_player >= 200000) {
        rpg->spritesheet[S_PLAYER].rect.left += 48;
        if (rpg->all_events.down)
            rpg->spritesheet[S_PLAYER].rect.top = 0;
        if (rpg->all_events.up)
            rpg->spritesheet[S_PLAYER].rect.top = 64 * 3;
        if (rpg->all_events.left)
            rpg->spritesheet[S_PLAYER].rect.top = 64 * 1;
        if (rpg->all_events.right)
            rpg->spritesheet[S_PLAYER].rect.top = 64 * 2;
        if (rpg->spritesheet[S_PLAYER].rect.left >= 192)
            rpg->spritesheet[S_PLAYER].rect.left = 0;
        sfClock_restart(rpg->spritesheet[S_PLAYER].clock);
    }

    if (color.g == 255 && rpg->spritesheet[S_PLAYER].rect.top < 256)
        rpg->spritesheet[S_PLAYER].rect.top += 256;
    else if (color.g != 255 && rpg->spritesheet[S_PLAYER].rect.top >= 256)
        rpg->spritesheet[S_PLAYER].rect.top -= 256;
}
