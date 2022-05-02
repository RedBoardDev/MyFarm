/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** choose_skin1.c
*/

#include "../../../include/rpg.h"

void skin_blue(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_BLUE;
}

void skin_brown(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_BROWN;
}

void skin_cyan(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_CYAN;
}

void skin_green(rpg_t *rpg)
{
    rpg->player_stats.skin = SP_PLAYER_GREEN;
}
