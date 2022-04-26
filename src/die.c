/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** die.c
*/

#include "../include/rpg.h"

void return_home(rpg_t *rpg)
{
    init_all_events(&rpg->all_events);
    rpg->player_stats.incr_pos.x = 0;
    rpg->player_stats.incr_pos.y = 0;
    rpg->player_stats.speed = 1.0;
    rpg->player_stats.life = 20.0;
    move_life_bar(rpg, rpg->player_stats.life * 5);
    rpg->begin.view.center = rpg->screen[SC_MAIN_MAP].view_pos;
    for (int i = 0; i < NBR_SP; ++i)
        rpg->spritesheet[i].active = false;
    for (int i = 0; i < NBR_SC; ++i)
        rpg->screen[i].active = false;
    toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    rpg->begin.view.center = (sfVector2f){SPAWN_X, SPAWN_Y};
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
}

void die(rpg_t *rpg)
{
    return_home(rpg);
}
