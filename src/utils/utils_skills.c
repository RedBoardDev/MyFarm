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

