/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_sounds.c
*/

#include "../../include/rpg.h"

static void init_sound_music(rpg_t *rpg)
{
    create_sound("assets/sounds/ambiant_graveyard.ogg",
    true, &rpg->sound.sound_list[SOUND_GRAVEYARD]);
    create_sound("assets/sounds/main_sound.ogg",
    true, &rpg->sound.sound_list[SOUND_MAIN]);
    create_sound("assets/sounds/ambiant_cave.ogg",
    true, &rpg->sound.sound_list[SOUND_AMBIANT_CAVE]);
    create_sound("assets/sounds/main.ogg",
    true, &rpg->sound.sound_list[SOUND_MENU]);
}

static void init_sound_effect(rpg_t *rpg)
{
    create_sound("assets/sounds/walk.ogg",
    false, &rpg->sound.sound_list[SOUND_WALK]);
    create_sound("assets/sounds/door.ogg",
    false, &rpg->sound.sound_list[SOUND_DOOR]);
    create_sound("assets/sounds/ambiant_cave.ogg",
    true, &rpg->sound.sound_list[SOUND_AMBIANT_CAVE]);
    create_sound("assets/sounds/die_player.ogg",
    false, &rpg->sound.sound_list[SOUND_DIE_PLAYER]);
    create_sound("assets/sounds/launch_weapon_player.ogg",
    false, &rpg->sound.sound_list[SOUND_LAUNCH_WEAPON_PLAYER]);
    create_sound("assets/sounds/golem_death.ogg",
    false, &rpg->sound.sound_list[SOUND_DEATH_GOLEM]);
}

void init_sounds(rpg_t *rpg, bool no_sound)
{
    rpg->sound.volume_music = (no_sound ? 0 : 50);
    rpg->sound.volume_effect = (no_sound ? 0 : 50);
    rpg->sound.volume_active = false;
    rpg->sound.sound_list = malloc(sizeof(sound_list_t) * NBR_SOUND);
    init_sound_music(rpg);
    init_sound_effect(rpg);
}
