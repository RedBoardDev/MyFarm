/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** draw_all.c
*/

#include "../include/rpg.h"

void draw_sfImage(sfRenderWindow *window, sfImage *image, sfVector2f pos,
sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfImage_createMaskFromColor(image, (sfColor){0, 0, 0, 100}, 100);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

static void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    sfVector2i po = sfMouse_getPositionRenderWindow(begin->window);
    spritesheet[SP_CURSOR].pos = sfRenderWindow_mapPixelToCoords(begin->window, po, begin->view.view);
    for (int i = 0; i < NBR_SP; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    send_chat_bubble_soldiers(rpg->begin.window, rpg);
    sfRenderWindow_display(rpg->begin.window);
}
