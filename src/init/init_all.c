/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../../include/rpg.h"

static void init_all2(rpg_t *rpg)
{
    rpg->index_old_s = 0;
    rpg->player_stats.skin = SP_PLAYER;
    init_notif(rpg);
    init_fps(rpg);
    init_all_events(&rpg->all_events);
    init_imgs(rpg);
    init_screens(rpg);
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_spritesheets(rpg->spritesheet);
}

void init_all(rpg_t *rpg, bool no_sound)
{
    init_all2(rpg);
    init_sounds(rpg, no_sound);
    init_params(rpg);
    init_csfml(&rpg->begin);
    init_view(rpg);
    init_player_boss_stats(&rpg->player_stats, &rpg->boss_stats);
    init_quests(rpg);
    init_inventory(&rpg->player_stats.inventory, rpg);
    init_icon_window(rpg);
    init_spritehseet_cutscenes(rpg);
    rpg->begin.fps.clock = sfClock_create();
    toggle_cursor(rpg->begin.window, false);
    sfWindow_setFramerateLimit((sfWindow *)rpg->begin.window, rpg->params.fps);
}
