/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../../include/rpg.h"

void init_all_events_mouse(events_t *events)
{
    events->mouse.left = false;
    events->mouse.left_released = false;
    events->mouse.right = false;
    events->mouse.move_x = 0;
    events->mouse.move_y = 0;
    events->mouse.pos = (sfVector2i){0, 0};
    events->mouse_wheel.up = false;
    events->mouse_wheel.down = false;
    events->mouse_wheel.click = false;
}

void init_all_events(events_t *events)
{
    events->left = false;
    events->right = false;
    events->up = false;
    events->down = false;
    events->page_up = false;
    events->page_down = false;
    events->z = false;
    events->q = false;
    events->s = false;
    events->d = false;
    events->e = false;
    events->escape = false;
    events->space = false;
    events->ctrl = false;
    events->tab = false;
    events->enter = false;
    init_all_events_mouse(events);
}

void init_player_stats(player_stats_t *player_stats)
{
    player_stats->incr_pos.x = 0;
    player_stats->incr_pos.y = 0;
    player_stats->money = 0;
    player_stats->speed = 1.0;
    player_stats->life = 20.0;
    player_stats->mana = 0.0;
    player_stats->damage = 1;
    player_stats->knowledge = 1;
    for (int i = 0; i < 10; ++i)
        player_stats->inventory[i] = -1;
}

void init_all(rpg_t *rpg)
{
    rpg->begin.fps.clock = sfClock_create();
    rpg->begin.fps.timer = 0;
    rpg->skin = SP_PLAYER;
    rpg->sound.volume = 0; //SET SOUND AT THE FINAL PUSH
    init_all_events(&rpg->all_events);
    init_imgs(rpg);
    init_screens(rpg);
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_view(rpg);
    init_spritesheets(rpg->spritesheet, &rpg->begin);
    init_sounds(rpg);
    init_csfml(&rpg->begin);
    init_player_stats(&rpg->player_stats);
}
