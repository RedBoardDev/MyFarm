/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** check_rush_to_player.c
*/

#include "../../../include/rpg.h"

void check_rush_to_player_executiner(rpg_t *rpg)
{
    if (check_collision_executioner(rpg)) {
        rpg->boss_stats.rush_to_player = false;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_attack);
        remove_life_player(rpg, rpg->boss_stats.damage_executioner * 2);
    }
}

void check_rush_to_player_golem(rpg_t *rpg)
{
    bool check = check_collision_golem_proj(rpg);

    if (check || rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x <=
    rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x -
    (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->boss_stats.status = ST_IDLE;
        rpg->boss_stats.rush_to_player = false;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos =
        rpg->spritesheet[SP_BOSS_GOLEM].pos;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = false;
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
        sfSprite_setRotation(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite, 0);
        if (check)
            remove_life_player(rpg, rpg->boss_stats.damage_golem);
    }
}
