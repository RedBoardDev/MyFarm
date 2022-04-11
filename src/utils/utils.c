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
