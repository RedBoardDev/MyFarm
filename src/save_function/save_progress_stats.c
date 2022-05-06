/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** save_progress_stats.c
*/

#include "../../include/rpg.h"

void save_player_stats(int fd, rpg_t *rpg)
{
    write(fd, &rpg->player_stats.incr_pos, sizeof(sfVector2f));
    write(fd, &rpg->player_stats.skin, sizeof(int));
    write(fd, &rpg->player_stats.money, sizeof(int));
    write(fd, &rpg->player_stats.speed, sizeof(float));
    write(fd, &rpg->player_stats.life, sizeof(float));
    write(fd, &rpg->player_stats.damage, sizeof(int));
    write(fd, &rpg->player_stats.attack, sizeof(bool));
    write(fd, &rpg->spritesheet[rpg->player_stats.skin].pos,
    sizeof(sfVector2f));
    for (int i = 0; i < 12; ++i)
        write(fd, &rpg->player_stats.inventory.inventory_case[i].
        item_spritesheet, sizeof(int));
}

void save_boss_stats(int fd, rpg_t *rpg)
{
    write(fd, &rpg->boss_stats.life, sizeof(float));
    write(fd, &rpg->boss_stats.damage_executioner, sizeof(int));
    write(fd, &rpg->boss_stats.damage_golem, sizeof(int));
    write(fd, &rpg->boss_stats.inc_pos, sizeof(float));
    write(fd, &rpg->boss_stats.status, sizeof(int));
    write(fd, &rpg->boss_stats.time_next_it, sizeof(float));
    write(fd, &rpg->boss_stats.rush_to_player, sizeof(bool));
}
