/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** struct.h
*/

#ifndef STRUCT_STATS_H
    #define STRUCT_STATS_H

    #include "structs_tools.h"

typedef struct {
    int item_spritesheet;
    sfVector2f pos;
} inventory_case_t;

typedef struct {
    inventory_case_t *inventory_case;
    sfText *money;
    sfText *attack;
    sfText *speed;
    sfText *life;
    sfText *quests;
    sfText *money_shop;
} inventory_t;

typedef struct {
    sfVector2f incr_pos;
    int skin;
    int money;
    float speed;
    float damage;
    float resistance;
    bool drunk;
    float life;
    bool attack;
    sfClock *drunk_time;
    sfClock *last_damage;
    inventory_t inventory;
} player_stats_t;

typedef struct {
    float life;
    int damage_executioner;
    int damage_golem;
    float inc_pos;
    int status;
    float time_next_it;
    bool rush_to_player;
    sfClock *movement;
} boss_stats_t;

#endif
