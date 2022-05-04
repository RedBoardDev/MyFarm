/*
** EPITECH PROJECT, 2022
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** menu
*/

#include "../../include/rpg.h"

bool draw_cursor_back_pause(rpg_t *rpg)
{
    int current_screen = get_current_screen(rpg);

    for (int i = 0; rpg->screen[current_screen].const_screen[i] != -1; ++i)
        if (rpg->screen[current_screen].const_screen[i] == SP_CURSOR)
            return (true);
    return (false);
}

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
    toggle_spritesheet_scene(rpg, !status, SC_PAUSE);
    if (status == true && draw_cursor_back_pause(rpg))
        rpg->spritesheet[SP_CURSOR].active = true;
}
