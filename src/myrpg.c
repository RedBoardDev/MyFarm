/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../include/rpg.h"

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
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
