/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_player1.c
*/

#include "../../include/rpg.h"

void init_all_players_2(spritesheet_t *spritesheet, beginning_t *begin, int i)
{
    set_one_sprite("assets/img/skins/grey.png", &spritesheet[SP_PLAYER_GREY],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/pink.png", &spritesheet[SP_PLAYER_PINK],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/red.png", &spritesheet[SP_PLAYER_RED],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/yellow.png",
    &spritesheet[SP_PLAYER_YELLOW],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
}

void init_all_players(spritesheet_t *spritesheet, beginning_t *begin)
{
    int i = 670;
    set_one_sprite("assets/img/skins/blue.png", &spritesheet[SP_PLAYER_BLUE],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/brown.png", &spritesheet[SP_PLAYER_BROWN],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/cyan.png", &spritesheet[SP_PLAYER_CYAN],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/green.png", &spritesheet[SP_PLAYER_GREEN],
    begin, (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i = 670;
    init_all_players_2(spritesheet, begin, i);
}
