/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** open_file_stats.c
*/

#include "../../include/rpg.h"

static void read_player_stats_inventory(int fd, rpg_t *rpg)
{
    int buff_int = 0;

    for (int i = 0; i < 12; ++i) {
        read(fd, &buff_int, sizeof(int));
        rpg->player_stats.inventory.inventory_case[i].item_spritesheet =
        buff_int;
    }
}

static void read_player_stats_other(int fd, rpg_t *rpg)
{
    sfVector2f buff_vect;
    int buff_int = 0;
    float buff_float = 0;
    bool buff_bool = false;
    read(fd, &buff_vect, sizeof(sfVector2f));
    rpg->player_stats.incr_pos = buff_vect;
    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.skin = buff_int;
    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.money = buff_int;
    read(fd, &buff_float, sizeof(float));
    rpg->player_stats.speed = buff_float;
    read(fd, &buff_float, sizeof(float));
    rpg->player_stats.life = buff_float;
    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.damage = buff_int;
    read(fd, &buff_bool, sizeof(bool));
    rpg->player_stats.attack = buff_bool;
    read(fd, &buff_vect, sizeof(sfVector2f));
    rpg->spritesheet[rpg->player_stats.skin].pos = buff_vect;
}

void read_player_stats(int fd, rpg_t *rpg)
{
    read_player_stats_other(fd, rpg);
    read_player_stats_inventory(fd, rpg);
}

void read_boss_stats(int fd, rpg_t *rpg)
{
    float buff_float = 0;
    int buff_int = 0;
    bool buff_bool = false;

    read(fd, &buff_float, sizeof(float));
    rpg->boss_stats.life = buff_float;
    read(fd, &buff_int, sizeof(int));
    rpg->boss_stats.damage_executioner = buff_int;
    read(fd, &buff_int, sizeof(int));
    rpg->boss_stats.damage_golem = buff_int;
    read(fd, &buff_float, sizeof(float));
    rpg->boss_stats.inc_pos = buff_float;
    read(fd, &buff_int, sizeof(int));
    rpg->boss_stats.status = buff_int;
    read(fd, &buff_float, sizeof(float));
    rpg->boss_stats.time_next_it = buff_float;
    read(fd, &buff_bool, sizeof(bool));
    rpg->boss_stats.rush_to_player = buff_bool;
}
