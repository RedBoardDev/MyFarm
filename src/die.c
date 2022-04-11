/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** die.c
*/

#include "../include/rpg.h"

extern int screen_game[];
extern int screen_grotte[];

void die(rpg_t *rpg)
{
    init_all_events(&rpg->all_events);
    rpg->player_stats.incr_pos.x = 0;
    rpg->player_stats.incr_pos.y = 0;
    rpg->player_stats.speed = 1.0;
    rpg->player_stats.life = 20.0;
    move_life_bar(rpg, rpg->player_stats.life * 5);
    rpg->begin.view.center = rpg->screen[SC_MAIN_MAP].view_pos;
    rpg->screen[SC_GROTTE].active = false;
    rpg->screen[SC_MAIN_MAP].active = true;
    toggle_spritesheet_scene(rpg, false, screen_grotte, SC_GROTTE);
    toggle_spritesheet_scene(rpg, true, screen_game, SC_MAIN_MAP);
    rpg->begin.view.center = (sfVector2f){SPAWN_X, SPAWN_Y};
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
}
