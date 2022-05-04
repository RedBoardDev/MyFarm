/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_player1.c
*/

#include "../../include/rpg.h"

void reset_all_players(rpg_t *rpg)
{
    sfVector2f scale = {3, 3};
    int posx = 670;
    int posy = HEIGHT / 2 + 100;

    for (int index = SP_PLAYER_BLUE; index <= SP_PLAYER_YELLOW; ++index) {
        if (index == SP_PLAYER_GREY) {
            posx = 670;
            posy = HEIGHT / 2 + 350;
        }
        rpg->spritesheet[index].rect.top = 0;
        rpg->spritesheet[index].pos.x = posx;
        rpg->spritesheet[index].pos.y = posy;
        sfSprite_setScale(rpg->spritesheet[index].sprite, scale);
        posx += 200;
    }
}

void init_all_players_2(spritesheet_t *spritesheet, int i)
{
    set_one_sprite("assets/img/skins/grey.png", &spritesheet[SP_PLAYER_GREY],
    (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/pink.png", &spritesheet[SP_PLAYER_PINK],
    (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/red.png", &spritesheet[SP_PLAYER_RED],
    (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/yellow.png",
    &spritesheet[SP_PLAYER_YELLOW],
    (init_sprite_t){{i, HEIGHT / 2 + 350}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
}

void init_all_players(spritesheet_t *spritesheet)
{
    int i = 670;
    set_one_sprite("assets/img/skins/blue.png", &spritesheet[SP_PLAYER_BLUE],
    (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/brown.png", &spritesheet[SP_PLAYER_BROWN],
    (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/cyan.png", &spritesheet[SP_PLAYER_CYAN],
    (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i += 200;
    set_one_sprite("assets/img/skins/green.png", &spritesheet[SP_PLAYER_GREEN],
    (init_sprite_t){{i, HEIGHT / 2 + 100}, {3, 3},
    {0, 0, 48, 62}, true, false, false});
    i = 670;
    init_all_players_2(spritesheet, i);
}
