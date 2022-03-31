/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** teleport.c
*/

#include "../include/rpg.h"

extern int screen_game[];
extern int screen_base[];
extern int screen_jail[];

void teleport_base(rpg_t *rpg)
{
    if (rpg->screen[GAME].active) {
        rpg->screen[GAME].active = false;
        // rpg->spritesheet[S_PLAYER].pos.y - 100;
        active_spritesheet_scene(false, screen_game, rpg->spritesheet);
        active_spritesheet_scene(true, screen_base, rpg->spritesheet);
    } else {
        rpg->screen[GAME].active = true;
        // rpg->spritesheet[S_PLAYER].pos.y + 10;
        active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        active_spritesheet_scene(true, screen_game, rpg->spritesheet);
    }
}

void teleport_jail(rpg_t *rpg)
{
    if (rpg->screen[GAME].active) {
        rpg->screen[GAME].active = false;
        // rpg->spritesheet[S_PLAYER].pos.y - 10;
        active_spritesheet_scene(false, screen_game, rpg->spritesheet);
        active_spritesheet_scene(true, screen_base, rpg->spritesheet);
    } else {
        rpg->screen[GAME].active = true;
        // rpg->spritesheet[S_PLAYER].pos.y + 10;
        active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        active_spritesheet_scene(true, screen_game, rpg->spritesheet);
    }
}

void teleport_player_scene(rpg_t *rpg)
{
    sfColor color;

    color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
    spritesheet[S_PLAYER].pos.x, rpg->spritesheet[S_PLAYER].pos.y});
    switch (color.b) {
    case M_BASE:
        teleport_base(rpg);
        break;
    case M_JAIL:
        teleport_jail(rpg);
        break;
    default:
        break;
    }
}
