/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** animations_boss_grotte.c
*/

#include "../../../include/rpg.h"

void animate_idle_golem(rpg_t *rpg)
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

void animate_die_golem(rpg_t *rpg)
{
    float time = get_clock_time(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);

    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.top != 700 &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.top != 800)
        rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 700;
    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.top == 700 &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.left == 0)
        play_sound(rpg->sound.sound_list[SOUND_DEATH_GOLEM].sound,
        rpg->sound.volume_effect);
    if (time >= SECOND_TO_MICRO(0.16)) {
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left += 100;
        sfClock_restart(rpg->spritesheet[SP_BOSS_GOLEM].c_anim);
    }
    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 700) {
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0;
        rpg->spritesheet[SP_BOSS_GOLEM].rect.top = 800;
    }
    if (rpg->spritesheet[SP_BOSS_GOLEM].rect.left >= 300 &&
    rpg->spritesheet[SP_BOSS_GOLEM].rect.top == 800)
        rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 300;
}

void animate_attack_proj_golem(rpg_t *rpg)
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
