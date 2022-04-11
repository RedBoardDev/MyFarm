/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** utils.c
*/

#include "../include/rpg.h"

int my_rand(int min, int max)
{
    return (min + rand() % ((max + 1) - min));
}

bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision)
{
    if (pos.x > collision.left &&
    pos.x < collision.left + collision.width &&
    pos.y > collision.top &&
    pos.y < collision.top + collision.height)
        return (true);
    else
        return (false);
}

void move_life_bar(rpg_t *rpg, int percentage)
{
    rpg->spritesheet[SP_LIFE_BAR].rect.width = percentage * 3.6;
    sfSprite_setTextureRect(rpg->spritesheet[SP_LIFE_BAR].sprite,
    rpg->spritesheet[SP_LIFE_BAR].rect);
}
