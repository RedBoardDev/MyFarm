/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_skills.c
*/

#include "../../include/rpg.h"

int add_money(rpg_t *rpg, int nbr)
{
    rpg->player_stats.money += nbr;
    return (0);
}

int remove_money(rpg_t *rpg, int nbr)
{
    if (rpg->player_stats.money < nbr)
        return (84);
    rpg->player_stats.money -= nbr;
    return (0);
}

void add_life(rpg_t *rpg, int nbr)
{
    rpg->player_stats.life += nbr;
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
