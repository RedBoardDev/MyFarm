/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../include/rpg.h"

void set_view(rpg_t *rpg)
{
    sfView *view = sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    sfView_setCenter(view, (sfVector2f){WIDTH / 2, HEIGHT / 2});
    sfView_zoom(view, 0.25);
    sfRenderWindow_setView(rpg->begin.window, view);
}

void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SPRITE; ++i)
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
    set_view(rpg);
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    sfRenderWindow_display(rpg->begin.window);
}

void big_loop(rpg_t *rpg)
{
    clean_window(&rpg->begin, sfBlack);
    my_events(&rpg->begin, &rpg->all_events);
    draw_all(rpg);
}

void myrpg(void)
{
    rpg_t rpg;

    init_all(&rpg);
    if (!rpg.begin.window || !rpg.begin.framebuffer)
        return;
    sfWindow_setFramerateLimit((sfWindow *)rpg.begin.window, 120);
    rpg.begin.fps.clock = sfClock_create();
    while (sfRenderWindow_isOpen(rpg.begin.window))
        big_loop(&rpg);
    destroy_all(&rpg.begin);
}
