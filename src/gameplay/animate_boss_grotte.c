/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animate_boss_grotte.c
*/

#include "../../include/rpg.h"

// static void animate_attack_1(rpg_t *rpg)
// {
//     float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

//     rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 0;
//     if (time >= 70000) {
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
//         sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
//     }
//     if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 1300)
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
// }

// static void animate_attack_2(rpg_t *rpg)
// {
//     float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

//     rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 100;
//     if (time >= 100000) {
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
//         sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
//     }
//     if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 1200)
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
// }

static void animate_idle(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

    rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 0;
    if (time >= SECOND_TO_MICRO(0.2)) {
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 400)
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
}

// static void animate_test(rpg_t *rpg)
// {
//     float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

//     rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 800;
//     if (time >= 100000) {
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
//         sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
//     }
//     if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 400)
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
// }

// static void animate_die(rpg_t *rpg)
// {
//     float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

//     rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 200;
//     if (time >= 70000) {
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
//         sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
//     }
//     if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 2000)
//         rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 2000;
// }

static void animate_attack_proj(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

    rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 200;
    if (time >= SECOND_TO_MICRO(0.1)) {
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 800)
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 800;
}

static void ia_boss_rush_to_player(rpg_t *rpg)
{
    bool check = check_collision_golem_proj(rpg);
    if (check || rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x <= rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x - (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->boss_stats.status = ST_IDLE;
        rpg->boss_stats.rush_to_player = false;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos = rpg->spritesheet[SP_BOSS_GOLEM].pos;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = false;
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
        if (check)
            remove_life_player(rpg, 10);
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

static void anim_attack_player(rpg_t *rpg)
{
    if (check_collision_hoe_to_golem(rpg) || rpg->spritesheet[SP_ITEM_HOE].pos.x >= rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x + (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->player_stats.attack = false;
        --rpg->boss_stats.life;
        rpg->spritesheet[SP_ITEM_HOE].pos = rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite, rpg->spritesheet[SP_ITEM_HOE].pos);
        rpg->spritesheet[SP_ITEM_HOE].active = false;
    }
}

static void attack_player(rpg_t *rpg)
{
    if (rpg->player_stats.attack)
        anim_attack_player(rpg);
    else if (rpg->all_events.enter && !rpg->player_stats.attack) {
        rpg->player_stats.attack = true;
        rpg->spritesheet[SP_ITEM_HOE].pos = rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite, rpg->spritesheet[SP_ITEM_HOE].pos);
    }
}

void animate_boss_grotte(rpg_t *rpg)
{
    rpg->spritesheet[rpg->player_stats.skin].pos.x = 444 - 200;

    attack_player(rpg);
    ia_boss(rpg);
    switch (rpg->boss_stats.status) {
        case ST_IDLE:
            animate_idle(rpg);
            break;
        case ST_ATTACK_1:
            animate_attack_proj(rpg);
        default:
            break;
    }
    // animate_test(rpg);

    // if (rpg->boss_stats.life <= 0) {
    //     rpg->boss_stats.status = ST_DIE;
    //     if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 2000) {
    //         toggle_spritesheet_scene(rpg, false, SC_CEMETERY);
    //         toggle_spritesheet_scene(rpg, true, SC_VICTORY_CEMETERY);
    //     }
    // }
    // else
    //     ia_boss(rpg);
    // switch (rpg->boss_stats.status) {
    //     case ST_IDLE:
    //         animate_idle(rpg);
    //         break;
    //     case ST_ATTACK_1:
    //         animate_attack_1(rpg);
    //         break;
    //     case ST_ATTACK_2:
    //         animate_attack_2(rpg);
    //         break;
    //     case ST_DIE:
    //         animate_die(rpg);
    //         break;
    //     default:
    //         break;
    // }
}
