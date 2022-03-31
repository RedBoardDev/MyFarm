/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../include/rpg.h"

const int screen_menu[] = {SP_BACKGROUND_SC_MENU, SP_PLAY, SP_QUIT, SP_CUSTOM, -1};
const int screen_game[] = {SP_BACKGROUND_SC_MAIN_MAP, SP_PLAYER, -1};
const int screen_base[] = {SP_BACKGROUND_SC_BASE, SP_PLAYER, -1};
const int screen_jail[] = {SP_BACKGROUND_JAIL, SP_PLAYER, -1};

void init_player(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/player.png", &spritesheet[SP_PLAYER],
    begin, (init_sprite_t){{SPAWN_X, SPAWN_Y}, {0.7, 0.7},
    {0, 0, 48, 62}, false, false});
}

void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin)
{
    init_background_main_map(spritesheet, begin);
    init_spritesheet_house(spritesheet, begin);
    init_player(spritesheet, begin);
    init_menu(spritesheet, begin);
}

void active_spritesheet_scene(bool status, int *screen_i,
spritesheet_t *spritesheet)
{
    for (int i = 0; screen_i[i] != -1; ++i)
        spritesheet[screen_i[i]].active = status;
}
