/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_boss_grotte.c
*/

#include "../../../include/rpg.h"

static void ia_boss_rush_to_player(rpg_t *rpg)
{
    bool check = check_collision_golem_proj(rpg);

    if (check || rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x <= rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x - (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->boss_stats.status = ST_IDLE;
        rpg->boss_stats.rush_to_player = false;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos = rpg->spritesheet[SP_BOSS_GOLEM].pos;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = false;
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
        sfSprite_setRotation(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite, 0);
        if (check)
            remove_life_player(rpg, rpg->boss_stats.damage_golem);
    }
}

static void ia_boss(rpg_t *rpg)
{
    float time_attack =
    get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_attack);

    if (rpg->boss_stats.rush_to_player) {
        ia_boss_rush_to_player(rpg);
    } else if (time_attack >= SECOND_TO_MICRO(0.1)) {
        rpg->boss_stats.status = ST_ATTACK_1;
        rpg->boss_stats.rush_to_player = true;
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos = rpg->spritesheet[SP_BOSS_GOLEM].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite, rpg->spritesheet[SP_BOSS_GOLEM].pos);
        sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_attack);
    }
}

static void player_rush_to_golem(rpg_t *rpg)
{
    bool check = check_collision_hoe_to_golem(rpg);

    if (check || rpg->spritesheet[SP_ITEM_HOE].pos.x >=
    rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x +
    (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->player_stats.attack = false;
        rpg->spritesheet[SP_ITEM_HOE].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite,
        rpg->spritesheet[SP_ITEM_HOE].pos);
        rpg->spritesheet[SP_ITEM_HOE].active = false;
        if (check) {
            rpg->boss_stats.life -= 2;
            rpg->boss_stats.life <= 0 ?
            rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0 : 0;
        }
    }
}

static void attack_player(rpg_t *rpg)
{
    if (rpg->player_stats.attack)
        player_rush_to_golem(rpg);
    else if (rpg->all_events.enter && !rpg->player_stats.attack) {
        rpg->player_stats.attack = true;
        rpg->spritesheet[SP_ITEM_HOE].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite,
        rpg->spritesheet[SP_ITEM_HOE].pos);
    }
}

void animate_boss_grotte(rpg_t *rpg)
{
    if (rpg->boss_stats.life <= 0) {
        rpg->boss_stats.status = ST_DIE;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = false;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos =
        rpg->spritesheet[SP_BOSS_GOLEM].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_BOSS_GOLEM_PROJ].sprite,
        rpg->spritesheet[SP_BOSS_GOLEM].pos);
    }
    attack_player(rpg);
    ia_boss(rpg);
    switch (rpg->boss_stats.status) {
        case ST_IDLE:
            animate_idle_golem(rpg);
            break;
        case ST_ATTACK_1:
            animate_attack_proj_golem(rpg);
            break;
        case ST_DIE:
            animate_die_golem(rpg);
            break;
        default:
            break;
    }
}
