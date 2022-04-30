/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_skills2.c
*/

#include "../../include/rpg.h"

void add_speed(rpg_t *rpg, int nbr)
{
    rpg->player_stats.life += nbr;
}

void add_attack(rpg_t *rpg, int nbr)
{
    rpg->player_stats.life += nbr;
}

void flask_drunk(rpg_t *rpg, int nbr)
{
    rpg->player_stats.life += nbr;
}
