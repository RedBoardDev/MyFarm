/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** my_exit.c
*/

#include "../include/rpg.h"

void my_exit(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->begin.window);
    for (int i = 0; i < NBR_SOUND; ++i) {
        sfSound_destroy(rpg->sound.sound_list[i].sound);
        sfSoundBuffer_destroy(rpg->sound.sound_list[i].sound_buffer);
    }
    for (int i = 0; i < NBR_SP; ++i) {
        // sfSprite_destroy(rpg->spritesheet[i].sprite);
        sfTexture_destroy(rpg->spritesheet[i].texture);
    }
    // sfView_destroy(&rpg->begin.view);
}
