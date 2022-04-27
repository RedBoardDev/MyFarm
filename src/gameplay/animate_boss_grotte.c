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
    if (time >= 200000) {
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

static void ia_boss_rush_to_player(rpg_t *rpg)
{
    if (check_collision_golem_proj(rpg)) {
        rpg->boss_stats.rush_to_player = false;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].pos.x = rpg->spritesheet[SP_BOSS_GOLEM].pos.x;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = false;
        remove_life_player(rpg, 2);
    }
}

static void ia_boss(rpg_t *rpg)
{
    float time_attack =
    get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_attack);

    if (rpg->boss_stats.rush_to_player) {
        ia_boss_rush_to_player(rpg);
    } else if (time_attack >= 7000000) {
        rpg->boss_stats.rush_to_player = true;
        rpg->spritesheet[SP_BOSS_GOLEM_PROJ].active = true;
        sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_attack);
    }
}

void animate_boss_grotte(rpg_t *rpg)
{
    rpg->spritesheet[rpg->player_stats.skin].pos.x = 444 - 200;

    ia_boss(rpg);
    switch (rpg->boss_stats.status) {
        case ST_IDLE:
            animate_idle(rpg);
            break;
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
