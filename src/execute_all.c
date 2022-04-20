/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_all.c
*/

#include "../include/rpg.h"

SCREENS_INT

// void execute_menu(rpg_t *rpg)
// {

// }

// void execute_help(rpg_t *rpg)
// {

// }

// void execute_main_map(rpg_t *rpg)
// {

// }

// void execute_base_player(rpg_t *rpg)
// {

// }

// void execute_inventory(rpg_t *rpg)
// {

// }

void execute_custom_skins(rpg_t *rpg)
{
    animate_selected_skin(rpg);
}

void execute_grotte(rpg_t *rpg)
{
    // if (rpg->all_events.page_down && rpg->boss_stats.life > 0) {
    //     --rpg->boss_stats.life;
    //     rpg->all_events.page_down = false;
    // }
    // if (rpg->all_events.page_up && rpg->boss_stats.life < 20) {
    //     ++rpg->boss_stats.life;
    //     rpg->all_events.page_up = false;
    // }
    move_life_bar(rpg, rpg->player_stats.life * 5);
    move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
    animate_boss(rpg);
    if (rpg->player_stats.life <= 0)
        die(rpg);
}

void execute_all_gameplay(rpg_t *rpg)
{
    animate_player(rpg);
    set_size_cursor(rpg, 0.06);
    manage_inventory(rpg);
    menu_pause(rpg);
}

void execute_all_menus(rpg_t *rpg)
{
    set_size_cursor(rpg, 0.15);
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}

void execute_all(rpg_t *rpg)
{
    if (is_in_gameplay(rpg))
        execute_all_gameplay(rpg);
    if (is_in_menu(rpg))
        execute_all_menus(rpg);
    if (rpg->screen[SC_CUSTOM_SKINS].active)
        execute_custom_skins(rpg);
    if (rpg->screen[SC_GROTTE].active)
        execute_grotte(rpg);
}