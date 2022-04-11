/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../../include/rpg.h"

void move_all_fps_independant(rpg_t *rpg)
{
    float delta = getClockTime_microsecond(rpg->begin.fps.clock) / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        move_player_and_view(rpg);
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
