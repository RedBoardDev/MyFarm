/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_menus.c
*/

#include "../../include/rpg.h"

void execute_all_menus(rpg_t *rpg)
{
    set_size_cursor(rpg, 0.15);
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}

void execute_taverne(rpg_t *rpg)
{
    if (check_collision_npc(rpg, SP_NPC_SELLER,
    (sfFloatRect){-15, -15, 60, 30}) && rpg->all_events.enter &&
    rpg->quest[QUEST_SELLER].active == -1) {
        put_shop_gui(rpg);
        rpg->all_events.enter = false;
    }
    if (check_collision_npc(rpg, SP_MAPS_TAVERNE,
    (sfFloatRect){-15, -15, 30, 30}) && rpg->all_events.enter) {
        open_big_maps(rpg);
        rpg->all_events.enter = false;
    }
}
