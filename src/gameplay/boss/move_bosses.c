/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_bosses.c
*/

#include "../../../include/rpg.h"

void move_proj_golem(rpg_t *rpg)
{
    if (rpg->boss_stats.rush_to_player &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.top == 200 &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 700) {
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = true;
        sfSprite_setRotation(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite, -5);
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x -= 5;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.y += 0.6;
        return;
    }
}

void move_proj_player(rpg_t *rpg)
{
    int hoe = get_item_inv(rpg, I_ATTACK);

    if (rpg->player_stats.attack && hoe != -1) {
        rpg->spritesheet[hoe].active = true;
        rpg->spritesheet[hoe].pos.x += 3;
        sfSprite_rotate(rpg->spritesheet[hoe].sprite, 10);
        return;
    }
}

static void move_executioner_rush(rpg_t *rpg)
{
    float diff = rpg->spritesheet[rpg->player_stats.skin].pos.x -
    rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x;

    if (rpg->boss_stats.rush_to_player) {
        if (diff < 0)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x -= 3;
        else if (diff > 0)
            rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x += 3;
        return;
    }
}

void move_executioner(rpg_t *rpg)
{
    sfColor color = {255, 255, 255, 255};

    move_executioner_rush(rpg);
    if (rpg->boss_stats.inc_pos < 0) {
        color = get_color_from_player(rpg->imgs_colors.backgrounds,
        (sfVector2f){rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x - 2,
        rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.y});
    }
    if (rpg->boss_stats.inc_pos > 0) {
        color = get_color_from_player(rpg->imgs_colors.backgrounds,
        (sfVector2f){rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x + 2,
        rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.y});
    }
    if (color.r != 255)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].pos.x +=
        rpg->boss_stats.inc_pos;
}
