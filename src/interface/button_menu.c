/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu.c
*/

#include "../../include/rpg.h"
extern int screen_menu[];
extern int screen_game[];

void launch_game(rpg_t *rpg)
{
    rpg->screen[SC_MENU].active = false;
    rpg->screen[SC_MAIN_MAP].active = true;
    sfView_zoom(rpg->begin.view.view , rpg->screen[SC_MAIN_MAP].view_zoom);
    stop_sound(rpg->sound.sound_list[SOUND_MENU].sound);
    toggle_spritesheet_scene(rpg, false, screen_menu, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, true, screen_game, rpg->spritesheet);
}

void quit_game(rpg_t *rpg)
{
    my_exit(rpg);
}

