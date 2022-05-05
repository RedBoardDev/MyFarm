/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move_player_cutscene.c
*/

#include "../../include/rpg.h"

static void move_animate_player(rpg_t *rpg, int touch)
{
    rpg->spritesheet[rpg->player_stats.skin].rect.left += 48;
    if (touch == 1)
        rpg->spritesheet[rpg->player_stats.skin].rect.top = 64 * 2;
    if (rpg->spritesheet[rpg->player_stats.skin].rect.left >= 192)
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
    sfClock_restart(rpg->spritesheet[rpg->player_stats.skin].c_anim);
}

void animate_player_cutscene(rpg_t *rpg, int touch)
{
    float time_player =
    get_clock_time(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    if (time_player >= SECOND_TO_MICRO(0.3))
        move_animate_player(rpg, touch);
}
