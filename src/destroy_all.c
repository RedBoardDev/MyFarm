/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** destroy_all.c
*/

#include "../include/rpg.h"

void destroy_spritesheets(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SP; ++i) {
        sfSprite_destroy(rpg->spritesheet[i].sprite);
        sfTexture_destroy(rpg->spritesheet[i].texture);
        sfClock_destroy(rpg->spritesheet[i].c_anim);
        sfClock_destroy(rpg->spritesheet[i].c_attack);
    }
    for (int i = 0; i < NBR_QUEST; ++i) {
        sfSprite_destroy(rpg->quest[i].bubulle.sprite);
        sfTexture_destroy(rpg->quest[i].bubulle.texture);
        sfClock_destroy(rpg->quest[i].bubulle.c_anim);
        sfClock_destroy(rpg->quest[i].bubulle.c_attack);
    }
    free(rpg->spritesheet);
}

void destroy_images(rpg_t *rpg)
{
    sfImage_destroy(rpg->imgs_colors.main_map);
    sfImage_destroy(rpg->imgs_colors.backgrounds);
}

void destroy_screens(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SC; ++i)
        sfClock_destroy(rpg->screen[i].clock);
    free(rpg->screen);
}

void destroy_sounds(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SOUND; ++i) {
        sfSound_destroy(rpg->sound.sound_list[i].sound);
        sfSoundBuffer_destroy(rpg->sound.sound_list[i].sound_buffer);
    }
    free(rpg->sound.sound_list);
}

void destroy_all(rpg_t *rpg)
{
    sfRenderWindow_destroy(rpg->begin.window);
    free(rpg->begin.framebuffer);
    sfTexture_destroy(rpg->begin.texture);
    sfSprite_destroy(rpg->begin.sprite);
    sfView_destroy(rpg->begin.view.view);
    sfClock_destroy(rpg->begin.fps.clock);
    destroy_spritesheets(rpg);
    destroy_images(rpg);
    destroy_screens(rpg);
    destroy_sounds(rpg);
    free(rpg);
}
