/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_sounds.c
*/

#include "../../include/rpg.h"

void init_sounds(rpg_t *rpg)
{
    rpg->sound.sound_list = malloc(sizeof(sound_list_t) * NBR_SOUND);
    create_sound("assets/sounds/main.ogg",
    true,&rpg->sound.sound_list[SOUND_MENU]);
    create_sound("assets/sounds/walk.ogg",
    false, &rpg->sound.sound_list[SOUND_WALK]);
    create_sound("assets/sounds/door.ogg",
    false, &rpg->sound.sound_list[SOUND_DOOR]);
}
