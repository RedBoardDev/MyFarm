/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myworld-martin.d-herouville
** File description:
** lib_sound.c
*/

#include "../include/rpg.h"

sfSound *create_sound(char *filepath)
{
    sfSound *sound;
    sfSoundBuffer *sound_buffer;

    sound_buffer = sfSoundBuffer_createFromFile(filepath);
    sound = sfSound_create();
    sfSound_setBuffer(sound, sound_buffer);
    sfSound_setVolume(sound, 0);
    return (sound);
}

void destroy_sound(sfSound *sound)
{
    sfSound_destroy(sound);
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
