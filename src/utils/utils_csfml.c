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
    sfClose | sfFullscreen, NULL);
    begin->framebuffer = my_framebuffer_create();
    begin->texture = sfTexture_create(WIDTH, HEIGHT);
    begin->sprite = sfSprite_create();
}

sfInt64 get_clock_time(sfClock *clock)
{
    return (sfClock_getElapsedTime(clock).microseconds);
}

sfColor get_color_from_player(sfImage *image, sfVector2f pos)
{
    return (sfImage_getPixel(image, pos.x, pos.y + 15));
}

void set_zoom(sfView *view, float new_zoom)
{
    sfView_reset(view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(view, new_zoom);
}
