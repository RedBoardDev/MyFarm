/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../include/rpg.h"

void set_limits_player(rpg_t *rpg)
{
    if (rpg->spritesheet[S_PLAYER].pos.x < 17)
        rpg->spritesheet[S_PLAYER].pos.x = 17;
    if (rpg->spritesheet[S_PLAYER].pos.y < -391)
        rpg->spritesheet[S_PLAYER].pos.y = -391;
    if (rpg->spritesheet[S_PLAYER].pos.x > 1905)
        rpg->spritesheet[S_PLAYER].pos.x = 1905;
    if (rpg->spritesheet[S_PLAYER].pos.y > 1471)
        rpg->spritesheet[S_PLAYER].pos.y = 1471;
}

void move_player_and_view(rpg_t *rpg)
{
    if (rpg->all_events.right) {
        if (rpg->spritesheet[S_PLAYER].pos.x > 385 && rpg->begin.view.center.x < 1535)
            rpg->begin.view.center.x += 2;
        rpg->spritesheet[S_PLAYER].pos.x += 2;
    }
    if (rpg->all_events.left) {
        if (rpg->spritesheet[S_PLAYER].pos.x < 1535 && rpg->begin.view.center.x > 385)
            rpg->begin.view.center.x -= 2;
        rpg->spritesheet[S_PLAYER].pos.x -= 2;
    }
    if (rpg->all_events.up) {
        if (rpg->spritesheet[S_PLAYER].pos.y < 1282 && rpg->begin.view.center.y > -203)
            rpg->begin.view.center.y -= 2;
        rpg->spritesheet[S_PLAYER].pos.y -= 2;
    }
    if (rpg->all_events.down) {
        if (rpg->spritesheet[S_PLAYER].pos.y > -203 && rpg->begin.view.center.y < 1282)
            rpg->begin.view.center.y += 2;
        rpg->spritesheet[S_PLAYER].pos.y += 2;
    }
    set_limits_player(rpg);
    set_view(rpg);
}

void move_all_fps_independant(rpg_t *rpg)
{
    float delta = sfClock_getElapsedTime(rpg->begin.fps.clock).microseconds / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        move_player_and_view(rpg);
        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
