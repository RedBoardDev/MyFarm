/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move_player_view.c
*/

#include "../../include/rpg.h"

static bool color_is_white(sfColor color)
{
    return (color.r == 254 && color.g == 254 && color.b == 254);
}

float getsp(rpg_t *rpg, sfColor color)
{
    sfSoundStatus st;

    if (color_is_white(color)) {
        st = sfSound_getStatus(rpg->sound.sound_list[SOUND_WATER].sound);
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WATER].sound,
            rpg->sound.volume_effect);
        stop_sound(rpg->sound.sound_list[SOUND_WALK].sound);
        return (SPEED_PLAYER / 4);
    } else {
        st = sfSound_getStatus(rpg->sound.sound_list[SOUND_WALK].sound);
        if (st != sfPlaying)
            play_sound(rpg->sound.sound_list[SOUND_WALK].sound,
            rpg->sound.volume_effect / 1.9);
        stop_sound(rpg->sound.sound_list[SOUND_WATER].sound);
        return (SPEED_PLAYER * (rpg->player_stats.speed / 10 + 1));
    }
}
