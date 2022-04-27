/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animations_executioner.c
*/

#include "../../../include/rpg.h"

void animate_attack_1_executioner(rpg_t *rpg)
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

void animate_attack_2_executioner(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 100;
    if (time >= SECOND_TO_MICRO(0.1)) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 1200)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 0;
}

void animate_idle_executioner(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 300;
    if (time >= SECOND_TO_MICRO(0.2)) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 400)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 0;
}

void animate_die_executioner(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);

    rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.top = 200;
    if (time >= SECOND_TO_MICRO(0.07)) {
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_EXECUTIONER].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left >= 2000)
        rpg->spritesheet[SP_BOSS_EXECUTIONER].rect.left = 2000;
}
