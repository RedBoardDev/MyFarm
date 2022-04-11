/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** choose_skin2.c
*/

#include "../../../include/rpg.h"

void skin_grey(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_GREY;
}

void skin_pink(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_PINK;
}

void skin_red(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_RED;
}

void skin_yellow(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_YELLOW;
}
