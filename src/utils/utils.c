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
