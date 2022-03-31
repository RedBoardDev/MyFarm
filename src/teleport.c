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
    if (rpg->screen[SC_MAIN_MAP].active) {
        rpg->screen[SC_MAIN_MAP].active = false;
        rpg->screen[SC_BASE].active = true;
        // rpg->spritesheet[SP_PLAYER].pos.y - 100;
        active_spritesheet_scene(false, screen_game, rpg->spritesheet);
        active_spritesheet_scene(true, screen_base, rpg->spritesheet);
    } else {
        rpg->screen[SC_MAIN_MAP].active = true;
        rpg->screen[SC_BASE].active = false;
        rpg->spritesheet[SP_PLAYER].pos = (sfVector2f){SPAWN_X + 35, SPAWN_Y};
        rpg->begin.view.center = (sfVector2f){SPAWN_X, SPAWN_Y};
        // rpg->spritesheet[SP_PLAYER].pos.y + 10;
        active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        active_spritesheet_scene(true, screen_game, rpg->spritesheet);
    }
}

void teleport_jail(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        rpg->screen[SC_MAIN_MAP].active = false;
        rpg->screen[SC_BASE].active = true;
        // rpg->spritesheet[SP_PLAYER].pos.y - 10;
        active_spritesheet_scene(false, screen_game, rpg->spritesheet);
        active_spritesheet_scene(true, screen_base, rpg->spritesheet);
    } else {
        rpg->screen[SC_MAIN_MAP].active = true;
        rpg->screen[SC_BASE].active = false;
        // rpg->spritesheet[SP_PLAYER].pos.y + 10;
        active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        active_spritesheet_scene(true, screen_game, rpg->spritesheet);
    }
}

void teleport_player_scene(rpg_t *rpg, sfImage *image, sfVector2f pos_player)
{
    sfColor color;

    color = get_color_from_player(image, pos_player);
    switch (color.b) {
    case B_BASE:
        teleport_base(rpg);
        break;
    case B_JAIL:
        teleport_jail(rpg);
        break;
    default:
        break;
    }
}
