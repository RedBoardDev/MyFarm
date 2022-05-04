/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** utils.c
*/

#include "../../include/rpg.h"

void remove_life_player(rpg_t *rpg, int offset)
{
    if (get_item_inv(rpg, I_ARMOR) != -1)
        offset /= 1.1;
    rpg->player_stats.life -= offset;
    sfClock_restart(rpg->player_stats.last_damage);
}
