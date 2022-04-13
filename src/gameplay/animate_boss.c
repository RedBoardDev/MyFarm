/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_boss.c
*/

#include "../../include/rpg.h"

void animate_attack_1(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 0;
    if (time >= 70000) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 1300)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 0;
}

void animate_attack_2(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 100;
    if (time >= 100000) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 1200)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 0;
}

void animate_idle(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 300;
    if (time >= 200000) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 400)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 0;
}

void animate_die(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 200;
    if (time >= 70000) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 2000)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 2000;
}

void ia_boss_rush_to_player(rpg_t *rpg)
{
    if (check_collision_executioner(rpg)) {
        rpg->boss_stats.rush_to_player = false;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_attack);
        remove_life_player(rpg, 2);
    }
}

void ia_boss(rpg_t *rpg)
{
    float time_movement = get_clock_time(rpg->boss_stats.movement);
    float time_attack = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_attack);
    float time_last_damage = get_clock_time(rpg->player_stats.last_damage);
    int random = 0;

    if (time_movement >= 1000000) {
        random = my_rand(0, 1);
        random ? rpg->boss_stats.inc_pos *= -1 : 0;
        sfClock_restart(rpg->boss_stats.movement);
    }
    if (time_attack >= 10000000)
        rpg->boss_stats.rush_to_player = true;
    if (rpg->boss_stats.rush_to_player)
        ia_boss_rush_to_player(rpg);
    else if (check_collision_executioner(rpg)) {
        rpg->boss_stats.status = ST_ATTACK_1;
        if (time_last_damage >= 500000)
            remove_life_player(rpg, 1);
    } else
        rpg->boss_stats.status = ST_IDLE;
}

void animate_boss(rpg_t *rpg)
{
    if (rpg->boss_stats.life <= 0)
        rpg->boss_stats.status = ST_DIE;
    else
        ia_boss(rpg);
    switch (rpg->boss_stats.status) {
        case ST_IDLE:
            animate_idle(rpg);
            break;
        case ST_ATTACK_1:
            animate_attack_1(rpg);
            break;
        case ST_ATTACK_2:
            animate_attack_2(rpg);
            break;
        case ST_DIE:
            animate_die(rpg);
            break;
        default:
            break;
    }
}
