/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_all.c
*/

#include "../../include/rpg.h"

void execute_all(rpg_t *rpg)
{
    if (is_in_gameplay(rpg))
        execute_all_gameplay(rpg);
    if (is_in_menu(rpg))
        execute_all_menus(rpg);
    if (rpg->screen[SC_CUSTOM_SKINS].active)
        animate_selected_skin(rpg);
    if (rpg->screen[SC_GROTTE].active)
        execute_grotte(rpg);
    if (rpg->screen[SC_CEMETERY].active)
        execute_cemetery(rpg);
    if (rpg->screen[SC_MAIN_MAP].active)
        execute_main_map(rpg);
    if (rpg->screen[SC_BASE].active)
        execute_base(rpg);
    if (rpg->all_events.mouse.right)
        drink_flask(rpg);
    if (rpg->screen[SC_TAVERNE].active)
        execute_taverne(rpg);
    execute_quests(rpg);
}
