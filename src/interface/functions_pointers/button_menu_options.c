/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu_2.c
*/

#include "../../../include/rpg.h"

void button_resume_game(rpg_t *rpg)
{
    toggle_spritesheet_scene(rpg, false, SC_PAUSE);
}

void button_option_game(rpg_t *rpg)
{
    disable_all_screens_gameplay(rpg);
    toggle_spritesheet_scene(rpg, true, SC_OPTION);
    set_view(rpg, rpg->screen[SC_OPTION].view_pos);
}

void button_leave_game(rpg_t *rpg)
{
    disable_all_screens_gameplay(rpg);
    toggle_spritesheet_scene(rpg, false, SC_PAUSE);
    toggle_spritesheet_scene(rpg, true, SC_MENU);
}

void quit_game(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->begin.window);
}
