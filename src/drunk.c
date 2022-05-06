/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** drunk.c
*/

#include "../include/rpg.h"

static void change_all_sprites_colors(rpg_t *rpg, sfColor c)
{
    for (int i = 0; i < NBR_SP; ++i)
        sfSprite_setColor(rpg->spritesheet[i].sprite, c);
}

static void reset_colors_sprites(rpg_t *rpg)
{
    sfColor c = {255, 255, 255, 255};
    for (int i = 0; i < NBR_SP; ++i)
        sfSprite_setColor(rpg->spritesheet[i].sprite, c);
}

void make_drunk(rpg_t *rpg, sfColor c)
{
    if (rpg->player_stats.drunk) {
        change_all_sprites_colors(rpg, c);
        if (get_clock_time(rpg->player_stats.drunk_time) >=
        SECOND_TO_MICRO(30)) {
            rpg->player_stats.drunk = false;
            rpg->player_stats.speed -= SPEED_DRUNK;
            reset_colors_sprites(rpg);
        }
    }
}
