/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** lib_sound.c
*/

#include "../include/rpg.h"

void create_sound(char *filepath, bool loop, sound_list_t *sound_list)
{
    sound_list->sound_buffer = sfSoundBuffer_createFromFile(filepath);
    sound_list->sound = sfSound_create();
    sfSound_setBuffer(sound_list->sound, sound_list->sound_buffer);
    sfSound_setLoop(sound_list->sound, loop);
    sfSound_setVolume(sound_list->sound, 0);
}

void destroy_sound(sfSound *sound, sfSoundBuffer *sound_buffer)
{
    sfSound_destroy(sound);
    sfSoundBuffer_destroy(sound_buffer);
}

void play_sound(sfSound *sound, float volume)
{
    sfSound_setVolume(sound, volume);
    sfSound_play(sound);
}

void stop_sound(sfSound *sound)
{
    sfSound_stop(sound);
}

void play_main_sound(rpg_t *rpg)
{
    play_sound(rpg->sound.sound_list[SOUND_MAIN].sound,
    rpg->sound.volume_music);
}
