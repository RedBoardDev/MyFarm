/*
** EPITECH PROJECT, 2021
** myrunner
** File description:
** draw.c
*/

#include "../include/rpg.h"

void my_draw_rectangle(sfUint8 *framebuffer, sfIntRect rect, sfColor color)
{
    for (int i = rect.left; rect.width > i; ++i)
        for (int j = rect.top; rect.height > j; ++j)
            *(sfColor *)(4 * (j * WIDTH + i) + framebuffer) = color;
}

void my_clear_framebuffer(sfUint8 *framebuffer)
{
    my_draw_rectangle(framebuffer, (sfIntRect){0, 0, WIDTH, HEIGHT},
    sfTransparent);
}

void clean_window(beginning_t *begin, sfColor color)
{
    sfRenderWindow_clear(begin->window, color);
    my_clear_framebuffer(begin->framebuffer);
}
