/*
** EPITECH PROJECT, 2021
** myscreensaver
** File description:
** draw_simple.c
*/

#include "../../include/rpg.h"

void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color)
{
    x < 0 ? x = 1, color.a = 0 : x;
    x >= WIDTH ? x = WIDTH - 2, color.a = 0 : x;
    y < 0 ? y = 1, color.a = 0 : y;
    y >= HEIGHT ? y = HEIGHT - 2, color.a = 0 : y;
    *(sfColor *)(4 * (y * WIDTH + x) + framebuffer) = color;
}

void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color)
{
    for (unsigned int i = 0; size > i; ++i)
        for (unsigned int j = 0; size > j; ++j)
            *(sfColor *)(4 * (j * WIDTH + i) + framebuffer) = color;
}

void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius,
sfColor color)
{
    int xi = 0;
    int yi = 0;

    for (int i = center.x - radius; i < center.x + radius * 2; ++i)
        for (int j = center.y - radius;
        j < center.y + radius * 2; ++j) {
            xi = (i - center.x) * (i - center.x);
            yi = (j - center.y) * (j - center.y);
            sqrt(xi + yi) < radius ? my_putpixel(i, j, framebuffer, color) : 0;
        }
}

void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b,
sfColor color)
{
    int x = 0;
    int y = 0;

    for (float n = 0; n <= 1; n += 0.001) {
        x = point_a.x + (point_b.x - point_a.x) * n;
        y = point_a.y + (point_b.y - point_a.y) * n;
        my_putpixel(x, y, framebuffer, color);
    }
}
