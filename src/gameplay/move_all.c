/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../../include/rpg.h"

void move_all_fps_independant(rpg_t *rpg)
{
    float delta = sfClock_getElapsedTime(rpg->begin.fps.clock).microseconds
    / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        move_player_and_view(rpg);
        // if (rpg->screen[SC_MAIN_MAP].active) {
        //     Particle
        // }
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
