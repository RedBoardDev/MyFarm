/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../../include/rpg.h"

void move_all_fps_independant(rpg_t *rpg)
{
    float delta = get_clock_time(rpg->begin.fps.clock) / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        move_player_and_view(rpg);
        if (rpg->screen[SC_GROTTE].active) {
            move_proj_golem(rpg);
            move_proj_player(rpg);
        }
        if (rpg->screen[SC_CEMETERY].active)
            move_executioner(rpg);
        move_notif(rpg);
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
