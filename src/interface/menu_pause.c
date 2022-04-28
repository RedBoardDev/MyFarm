/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** menu
*/

#include "../../include/rpg.h"

void menu_pause(rpg_t *rpg)
{
    bool status = rpg->screen[SC_PAUSE].active;

    if (rpg->screen[SC_MENU].active || rpg->screen[SC_HOW_PLAY].active)
        return;
    rpg->spritesheet[SP_RESUME].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_RESUME].pos.y = rpg->begin.view.center.y - 70;
    rpg->spritesheet[SP_OPTION].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_OPTION].pos.y = rpg->begin.view.center.y;
    rpg->spritesheet[SP_LEAVE_GAME].pos.x = rpg->begin.view.center.x;
    rpg->spritesheet[SP_LEAVE_GAME].pos.y = rpg->begin.view.center.y + 70;
    if (rpg->all_events.escape) {
        rpg->all_events.escape = false;
        rpg->screen[SC_PAUSE].active = !status;
        toggle_spritesheet_scene(rpg, !status, SC_PAUSE);
    }
}
