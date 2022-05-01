/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_csfml.c
*/

#include "../../include/rpg.h"

sfUint8 *my_framebuffer_create(void)
{
    sfUint8 *framebuffer = malloc(sizeof(sfUint8) * (WIDTH * HEIGHT * 4));
    return (framebuffer);
}

void init_csfml(beginning_t *begin)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    begin->window = sfRenderWindow_create(mode, "My RPG",
    sfClose | sfResize | sfFullscreen, NULL);
    begin->framebuffer = my_framebuffer_create();
    begin->texture = sfTexture_create(WIDTH, HEIGHT);
    begin->sprite = sfSprite_create();
}

void re_create_window(rpg_t *rpg, bool fullscreen)
{
    sfVideoMode mode = {WIDTH, HEIGHT, 32};

    sfRenderWindow_close(rpg->begin.window);
    sfRenderWindow_destroy(rpg->begin.window);
    if (fullscreen)
        rpg->begin.window = sfRenderWindow_create(mode, "My RPG",
        sfClose | sfResize | sfFullscreen, NULL);
    else
        rpg->begin.window = sfRenderWindow_create(mode, "My RPG",
        sfClose | sfResize, NULL);
    sfWindow_setFramerateLimit((sfWindow *)rpg->begin.window, rpg->params.fps);
    sfWindow_setIcon((sfWindow *)rpg->begin.window, 512, 512,
    rpg->begin.pixels);
    toggle_cursor(rpg->begin.window, false);
}

sfInt64 get_clock_time(sfClock *clock)
{
    return (sfClock_getElapsedTime(clock).microseconds);
}

sfColor get_color_from_player(sfImage *image, sfVector2f pos)
{
    return (sfImage_getPixel(image, pos.x, pos.y + 15));
}
