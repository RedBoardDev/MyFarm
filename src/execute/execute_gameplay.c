/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_gameplay.c
*/

#include "../../include/rpg.h"

void execute_all_gameplay(rpg_t *rpg)
{
    animate_player(rpg);
    set_size_cursor(rpg, 0.06);
    manage_inventory(rpg);
    if (rpg->all_events.escape) {
        rpg->all_events.escape = false;
        if (rpg->screen[SC_GUI_SHOP].active) {
            toggle_spritesheet_scene(rpg, false, SC_GUI_SHOP);
            rpg->spritesheet[SP_CURSOR].active = true;
            return;
        }
        if (rpg->spritesheet[SP_MINIMAP_TAVERNE].active) {
            rpg->spritesheet[SP_MINIMAP_TAVERNE].active = false;
            return;
        }
        if (rpg->screen[SC_INVENTORY].active) {
            for (int i = SP_ITEM_SHOVEL; i <= SP_FLASK_REVIVE; ++i)
                rpg->spritesheet[i].active = false;
            toggle_spritesheet_scene(rpg, false, SC_INVENTORY);
            return;
        } else if (!rpg->screen[SC_TAVERNE].active)
            menu_pause(rpg);
    }
}

void execute_main_map(rpg_t *rpg)
{
    collision_pee(rpg);
    if (rpg->quest[QUEST_GUIDE].step >= 65)
        collision_milk(rpg);
    if (get_clock_time(rpg->spritesheet[SP_NPC_GUIDE].c_anim) >=
    SECOND_TO_MICRO(30) && rpg->quest[QUEST_GUIDE].step == 0) {
        send_notif(rpg, "Talk to the guide!");
        sfClock_restart(rpg->spritesheet[SP_NPC_GUIDE].c_anim);
    }
}

void execute_quests(rpg_t *rpg)
{
    if (rpg->screen[SC_TENTE].active
    && rpg->quest[QUEST_SOLDIER].active != 1
    && check_collision_npc(rpg, SP_NPC_SOLDIER,
    (sfFloatRect){0, 0, 0, 0}))
        quest_launch(rpg, QUEST_SOLDIER, "assets/quest_dialog/soldiers.txt");
    if (rpg->screen[SC_TAVERNE].active
    && rpg->quest[QUEST_SELLER].active != 1
    && check_collision_npc(rpg, SP_NPC_SELLER,
    (sfFloatRect){-15, -15, 60, 30}))
        quest_launch(rpg, QUEST_SELLER, "assets/quest_dialog/seller.txt");
    if (rpg->screen[SC_MAIN_MAP].active
    && rpg->quest[QUEST_GUIDE].active != 1
    && check_collision_npc(rpg, SP_NPC_GUIDE,
    (sfFloatRect){0, 0, 0, 0})) {
        quest_launch(rpg, QUEST_GUIDE, "assets/quest_dialog/guide.txt");
    }
}

void execute_base(rpg_t *rpg)
{
    sfFloatRect co = {-20, -20, 40, 40};
    if (check_collision_npc(rpg, SP_BED_SLEEP, co) && rpg->all_events.enter) {
        rpg->all_events.enter = false;
        button_bed_saving(rpg);
    }
}

void execute_taverne(rpg_t *rpg)
{
    if (check_collision_npc(rpg, SP_NPC_SELLER,
    (sfFloatRect){-15, -15, 60, 30}) && rpg->all_events.enter &&
    rpg->quest[QUEST_SELLER].active == -1) {
        put_shop_gui(rpg);
        rpg->all_events.enter = false;
    }
}
