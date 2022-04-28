/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu_2.c
*/

#include "../../../include/rpg.h"

void buttun_resume_game(rpg_t *rpg)
{
    toggle_spritesheet_scene(rpg, false, SC_PAUSE);
}

void buttun_option_game(rpg_t *rpg)
{
    disable_all_screens_gameplay(rpg);
    toggle_spritesheet_scene(rpg, true, SC_OPTION);
    sfView_setCenter(rpg->begin.view.view, rpg->screen[SC_OPTION].view_pos);
}

void buttun_leave_game(rpg_t *rpg)
{
    disable_all_screens_gameplay(rpg);
    toggle_spritesheet_scene(rpg, false, SC_PAUSE);
    toggle_spritesheet_scene(rpg, true, SC_MENU);
}

void quit_game(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->begin.window);
}

void button_toggle_fullscreen(rpg_t *rpg)
{
    if (rpg->begin.fullscreen) {
        rpg->begin.fullscreen = false;
        re_create_window(rpg, false);
        rpg->spritesheet[SP_BUTTON_SCREEN].rect.left = rpg->spritesheet[SP_BUTTON_SCREEN].rect.width;
    } else {
        rpg->begin.fullscreen = true;
        re_create_window(rpg, true);
        rpg->spritesheet[SP_BUTTON_SCREEN].rect.left = 0;
    }
}
