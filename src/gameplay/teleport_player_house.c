/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** teleport_player_house.c
*/

#include "../../include/rpg.h"

void teleport_base(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        set_view(rpg, rpg->screen[SC_BASE].view_pos);
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_BASE);
    } else {
        set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
        rpg->spritesheet[rpg->player_stats.skin].pos = rpg->begin.view.center;
        toggle_spritesheet_scene(rpg, false, SC_BASE);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    }
}

void teleport_tente(rpg_t *rpg)
{
    sfVector2f pos = {183, 432};

    if (rpg->screen[SC_MAIN_MAP].active) {
        set_view(rpg, rpg->screen[SC_TENTE].view_pos);
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_TENTE);
    } else {
        rpg->spritesheet[rpg->player_stats.skin].pos = pos;
        set_view(rpg, (sfVector2f){rpg->begin.view.center.x, pos.y});
        toggle_spritesheet_scene(rpg, false, SC_TENTE);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
        set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
    }
}

void teleport_jail(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        rpg->spritesheet[rpg->player_stats.skin].pos.x -= 40;
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_JAIL);
        set_view(rpg, rpg->screen[SC_JAIL].view_pos);
    } else {
        rpg->spritesheet[rpg->player_stats.skin].pos.x += 40;
        toggle_spritesheet_scene(rpg, false, SC_JAIL);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
        set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
    }
}

void teleport_taverne(rpg_t *rpg)
{
    sfVector2f pos = {854, 377};

    if (rpg->screen[SC_MAIN_MAP].active) {
        set_view(rpg, rpg->screen[SC_TAVERNE].view_pos);
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_TAVERNE);
    } else {
        toggle_spritesheet_scene(rpg, false, SC_TAVERNE);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
        rpg->spritesheet[rpg->player_stats.skin].pos = pos;
        set_view(rpg, pos);
    }
}
