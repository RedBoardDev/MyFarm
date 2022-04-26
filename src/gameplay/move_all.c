/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../../include/rpg.h"

void move_boss(rpg_t *rpg)
{
    sfColor color;
    float diff = rpg->spritesheet[rpg->player_stats.skin].pos.x -
    rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x;

    if (rpg->boss_stats.rush_to_player) {
        if (diff < 0)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x -= 3;
        else if (diff > 0)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x += 3;
        return;
    }
    if (rpg->boss_stats.inc_pos < 0) {
        color = get_color_from_player(rpg->imgs_colors.backgrounds,
        (sfVector2f){rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x - 2,
        rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.y});
        if (color.r != 255)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x +=
            rpg->boss_stats.inc_pos;
    }
    if (rpg->boss_stats.inc_pos > 0) {
        color = get_color_from_player(rpg->imgs_colors.backgrounds,
        (sfVector2f){rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x + 2,
        rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.y});
        if (color.r != 255)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x +=
            rpg->boss_stats.inc_pos;
    }
}

void move_all_fps_independant(rpg_t *rpg)
{
    float delta = get_clock_time(rpg->begin.fps.clock) / 1000;

    rpg->begin.fps.timer += delta;
    while (rpg->begin.fps.timer >= 8) {
        move_player_and_view(rpg);
        if (rpg->screen[SC_GROTTE].active || rpg->screen[SC_CEMETERY].active)
            move_boss(rpg);

        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
