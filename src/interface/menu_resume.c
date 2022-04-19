/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** menu
*/

#include "../../include/rpg.h"

SCREENS_INT

void menu_pause(rpg_t *rpg)
{
    bool status = rpg->screen[SC_PAUSE].active;

    rpg->spritesheet[SP_PAUSE].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_PAUSE].pos.y = rpg->begin.view.center.y - 100;
    if (rpg->all_events.c) {
        rpg->all_events.c = false;
        rpg->screen[SC_PAUSE].active = !status;
        toggle_spritesheet_scene(rpg, !status, screen_pause_menu, SC_PAUSE);
    }
}
