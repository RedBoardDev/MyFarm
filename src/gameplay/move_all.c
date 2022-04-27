/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_all.c
*/

#include "../../include/rpg.h"

static void move_proj_golem(rpg_t *rpg)
{
    // float diff = rpg->spritesheet[rpg->player_stats.skin].pos.x -
    // rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x;

    if (rpg->boss_stats.rush_to_player &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.top == 200 &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 700) {
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = true;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x -= 3;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.y += 0.2;
        // if (diff < 0)
        // else if (diff > 0)
        //     rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x += 3;
        return;
    }
    // if (rpg->boss_stats.inc_pos < 0) {
    //     color = get_color_from_player(rpg->imgs_colors.backgrounds,
    //     (sfVector2f){rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x - 2,
    //     rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.y});
    //     if (color.r != 255)
    //         rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x +=
    //         rpg->boss_stats.inc_pos;
    // }
    // if (rpg->boss_stats.inc_pos > 0) {
    //     color = get_color_from_player(rpg->imgs_colors.backgrounds,
    //     (sfVector2f){rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x + 2,
    //     rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.y});
    //     if (color.r != 255)
    //         rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x +=
    //         rpg->boss_stats.inc_pos;
    // }
}

static void move_proj_player(rpg_t *rpg)
{
    // float diff = rpg->spritesheet[SP_BOSS_GOLEM].pos.x -
    // rpg->spritesheet[SP_ITEM_HOE].pos.x;
    float rot = sfSprite_getRotation(rpg->spritesheet[SP_ITEM_HOE].sprite);

    rot += 10;
    if (rpg->player_stats.attack) {
        rpg->spritesheet[SP_ITEM_HOE].active = true;
        rpg->spritesheet[SP_ITEM_HOE].pos.x += 3;
        // if (diff < 0)
        //     rpg->spritesheet[SP_ITEM_HOE].pos.x -= 3;
        // else if (diff > 0)
        sfSprite_setRotation(rpg->spritesheet[SP_ITEM_HOE].sprite, rot);
        return;
    }
}

static void move_boss(rpg_t *rpg)
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
        if (rpg->screen[SC_GROTTE].active) {
            move_proj_golem(rpg);
            move_proj_player(rpg);
        }
        if (rpg->screen[SC_CEMETERY].active)
            move_boss(rpg);

        rpg->begin.fps.timer -= 8;
    }
    sfClock_restart(rpg->begin.fps.clock);
}
