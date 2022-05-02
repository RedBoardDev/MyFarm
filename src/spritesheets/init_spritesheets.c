/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../include/rpg.h"

void init_player(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/player.png", &spritesheet[SP_PLAYER],
    (init_sprite_t){{SPAWN_X, SPAWN_Y}, {0.7, 0.7},
    {0, 0, 48, 62}, false, false, false});
}

void init_life_bar(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/life_bar_box.png", &spritesheet[SP_LIFE_BAR_BOX],
    (init_sprite_t){{444 - 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
    set_one_sprite("assets/img/life_bar.png", &spritesheet[SP_LIFE_BAR],
    (init_sprite_t){{444 - 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
    set_one_sprite("assets/img/boss/boss_life_bar_box.png",
    &spritesheet[SP_LIFE_BAR_BOX_BOSS],
    (init_sprite_t){{444 + 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
    set_one_sprite("assets/img/boss/boss_life_bar.png",
    &spritesheet[SP_LIFE_BAR_BOSS],
    (init_sprite_t){{444 + 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false, false});
}

void init_spritesheets(spritesheet_t *spritesheet)
{
    init_main_map(spritesheet);
    init_spritesheets_rooms(spritesheet);
    init_player(spritesheet);
    init_all_players(spritesheet);
    init_menu(spritesheet);
    init_spritesheet_inventory(spritesheet);
    init_life_bar(spritesheet);
    init_spritesheets_food(spritesheet);
    init_spritesheets_armed(spritesheet);
    init_bosses(spritesheet);
    init_spritesheets_npc(spritesheet);
    init_spritesheets_quests(spritesheet);
    init_buttons_pause_menu(spritesheet);
    init_buttons_option_menu(spritesheet);
    init_spritesheet_gui_shop(spritesheet);
    init_spritesheets_flask(spritesheet);
    set_one_sprite("assets/img/cursor.png", &spritesheet[SP_CURSOR],
    (init_sprite_t){{444 - 320, 1196 - 197}, {0.10, 0.10},
    {0, 0, 181, 206}, false, false, false});
}
