/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_seleced_skin.c
*/

#include "../../include/rpg.h"

void animate_selected_skin(rpg_t *rpg)
{
    float time_player =
    get_clock_time(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    if (time_player >= SECOND_TO_MICRO(0.2)) {
        rpg->spritesheet[rpg->player_stats.skin].rect.left += 48;
        sfClock_restart(rpg->spritesheet[rpg->player_stats.skin].c_anim);
    }
    if (rpg->spritesheet[rpg->player_stats.skin].rect.left >= 192)
        rpg->spritesheet[rpg->player_stats.skin].rect.left = 0;
}
