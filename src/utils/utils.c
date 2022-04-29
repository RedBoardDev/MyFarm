/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils.c
*/

#include "../../include/rpg.h"

int my_rand(int min, int max)
{
    return (min + rand() % ((max + 1) - min));
}

sfColor my_rgb(sfColor color)
{
    if (color.r == 255 && color.b == 0)
        ++color.g;
    if (color.g == 255 && color.b == 0)
        --color.r;
    if (color.g == 255 && color.r == 0)
        ++color.b;
    if (color.b == 255 && color.r == 0)
        --color.g;
    if (color.b == 255 && color.g == 0)
        ++color.r;
    if (color.r == 255 && color.g == 0)
        --color.b;
    return (color);
}

void move_life_bar(rpg_t *rpg, int percentage)
{
    rpg->spritesheet[SP_LIFE_BAR].rect.width = percentage * 3.6;
    sfSprite_setTextureRect(rpg->spritesheet[SP_LIFE_BAR].sprite,
    rpg->spritesheet[SP_LIFE_BAR].rect);
}

void move_life_bar_boss(rpg_t *rpg, int percentage)
{
    rpg->spritesheet[SP_LIFE_BAR_BOSS].rect.width = percentage * 3.6;
    sfSprite_setTextureRect(rpg->spritesheet[SP_LIFE_BAR_BOSS].sprite,
    rpg->spritesheet[SP_LIFE_BAR_BOSS].rect);
}

int get_size_file(char *path)
{
    struct stat stats;

    stat(path, &stats);
    return (stats.st_size);
}

int array_len(const char **arr)
{
    int i = 0;

    for (; arr[i] != NULL; ++i);
    return (i);
}
