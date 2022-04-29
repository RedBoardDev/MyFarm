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
        rpg->spritesheet[rpg->player_stats.skin].pos =
        rpg->screen[SC_MAIN_MAP].view_pos;
        set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
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
        set_view(rpg, rpg->screen[SC_MAIN_MAP].view_pos);
        toggle_spritesheet_scene(rpg, false, SC_TENTE);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    }
}

void teleport_jail(rpg_t *rpg)
{
    printf("%0.0f %0.0f\n", rpg->spritesheet[rpg->player_stats.skin].pos.x, rpg->spritesheet[rpg->player_stats.skin].pos.y);
    if (rpg->screen[SC_MAIN_MAP].active) {
        set_view(rpg, rpg->screen[SC_JAIL].view_pos);
        toggle_spritesheet_scene(rpg, false, SC_MAIN_MAP);
        toggle_spritesheet_scene(rpg, true, SC_JAIL);
    } else {
        toggle_spritesheet_scene(rpg, false, SC_JAIL);
        toggle_spritesheet_scene(rpg, true, SC_MAIN_MAP);
    }
}
