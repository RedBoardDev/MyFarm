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
    if (rpg->screen[SC_MENU].active || rpg->screen[SC_HOW_PLAY].active)
        return; 
    bool status = rpg->screen[SC_PAUSE].active;

    rpg->spritesheet[SP_RESUME].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_RESUME].pos.y = rpg->begin.view.center.y - 70;
    rpg->spritesheet[SP_OPTION].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_OPTION].pos.y = rpg->begin.view.center.y;
    rpg->spritesheet[SP_LEAVE_GAME].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_LEAVE_GAME].pos.y = rpg->begin.view.center.y + 70;
    if (rpg->all_events.c) {
        rpg->all_events.c = false;
        rpg->screen[SC_PAUSE].active = !status;
        toggle_spritesheet_scene(rpg, !status, screen_pause_menu, SC_PAUSE);
    }
}
