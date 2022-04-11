/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../include/rpg.h"

void init_player(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/player.png", &spritesheet[SP_PLAYER],
    begin, (init_sprite_t){{SPAWN_X, SPAWN_Y}, {0.7, 0.7},
    {0, 0, 48, 62}, false, false, false});
}

void init_life_bar(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/life_bar_box.png", &spritesheet[SP_LIFE_BAR_BOX],
    begin, (init_sprite_t){{444 - 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
    set_one_sprite("assets/img/life_bar.png", &spritesheet[SP_LIFE_BAR],
    begin, (init_sprite_t){{444 - 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
}

void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin)
{
    init_main_map(spritesheet, begin);
    init_spritesheets_rooms(spritesheet, begin);
    init_player(spritesheet, begin);
    init_all_players(spritesheet, begin);
    init_menu(spritesheet, begin);
    init_soundbox(spritesheet, begin);
    init_inventory(spritesheet, begin);
    init_life_bar(spritesheet, begin);
    init_spritesheets_food(spritesheet, begin);
    init_spritesheets_armed(spritesheet, begin);
}
