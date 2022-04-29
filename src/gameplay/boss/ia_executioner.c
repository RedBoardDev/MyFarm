/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_boss.c
*/

#include "../../../include/rpg.h"

static void check_rush_to_player(rpg_t *rpg)
{
    if (check_collision_executioner(rpg)) {
        rpg->boss_stats.rush_to_player = false;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_attack);
        remove_life_player(rpg, rpg->boss_stats.damage_executioner);
    }
}

static void ia_executioner_rush(rpg_t *rpg)
{
    float time_last_damage = get_clock_time(rpg->player_stats.last_damage);

    if (rpg->boss_stats.rush_to_player)
        check_rush_to_player(rpg);
    else if (check_collision_executioner(rpg)) {
        rpg->boss_stats.status = ST_ATTACK_1;
        if (time_last_damage >= SECOND_TO_MICRO(0.5))
            remove_life_player(rpg, 1);
        if (rpg->all_events.enter && rpg->boss_stats.life >= 0) {
            --rpg->boss_stats.life;
            rpg->boss_stats.life <= 0 ? rpg->player_stats.money += 24 : 0;
            rpg->all_events.enter = false;
        }
    } else
        rpg->boss_stats.status = ST_IDLE;
}

static void ia_executioner(rpg_t *rpg)
{
    float time_movement = get_clock_time(rpg->boss_stats.movement);
    float time_attack =
    get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_attack);
    int random = 0;

    if (time_movement >= SECOND_TO_MICRO(1)) {
        random = my_rand(0, 1);
        random ? rpg->boss_stats.inc_pos *= -1 : 0;
        sfClock_restart(rpg->boss_stats.movement);
    }
    if (time_attack >= SECOND_TO_MICRO(10))
        rpg->boss_stats.rush_to_player = true;
    ia_executioner_rush(rpg);
}

static void switch_status(rpg_t *rpg)
{
    switch (rpg->boss_stats.status) {
        case ST_IDLE:
            animate_idle_executioner(rpg);
            break;
        case ST_ATTACK_1:
            animate_attack_1_executioner(rpg);
            break;
        case ST_ATTACK_2:
            animate_attack_2_executioner(rpg);
            break;
        case ST_DIE:
            animate_die_executioner(rpg);
            break;
        default:
            break;
    }
}

void animate_boss_cemetery(rpg_t *rpg)
{
    if (rpg->boss_stats.life <= 0) {
        rpg->boss_stats.status = ST_DIE;
        if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 2000) {
            rpg->spritesheet[SP_BACKGROUND_VICRORY_GROTTE].pos =
            rpg->screen[SC_VICTORY_CEMETERY].view_pos;
            rpg->spritesheet[SP_NEXT_GROTTE].pos = (sfVector2f)
            {rpg->screen[SC_VICTORY_CEMETERY].view_pos.x + 148,
            rpg->screen[SC_VICTORY_CEMETERY].view_pos.y + 110};
            toggle_spritesheet_scene(rpg, false, SC_CEMETERY);
            toggle_spritesheet_scene(rpg, true, SC_VICTORY_CEMETERY);
        }
    } else
        ia_executioner(rpg);
    switch_status(rpg);
}
