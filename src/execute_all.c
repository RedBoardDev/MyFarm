/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_all.c
*/

#include "../include/rpg.h"

static void execute_cemetery(rpg_t *rpg)
{
    rpg->spritesheet[SP_LIFE_BAR].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x - 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x - 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOSS].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x + 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX_BOSS].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x + 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    move_life_bar(rpg, rpg->player_stats.life * 5);
    move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
    animate_boss_cemetery(rpg);
    if (rpg->player_stats.life <= 0)
        die_player(rpg);
}

static void execute_grotte(rpg_t *rpg)
{
    rpg->spritesheet[SP_LIFE_BAR].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x - 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x - 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOSS].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x + 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX_BOSS].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x + 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    move_life_bar(rpg, rpg->player_stats.life * 5);
    move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
    animate_boss_grotte(rpg);
    if (rpg->player_stats.life <= 0)
        die_player(rpg);
}

static void execute_all_gameplay(rpg_t *rpg)
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
            for (int i = SP_ITEM_SHOVEL; i <= SP_FLASK_DRUNK; ++i)
                rpg->spritesheet[i].active = false;
            toggle_spritesheet_scene(rpg, false, SC_INVENTORY);
            return;
        } else if (!rpg->screen[SC_TAVERNE].active)
            menu_pause(rpg);
    }
}

static void execute_all_menus(rpg_t *rpg)
{
    set_size_cursor(rpg, 0.15);
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}

static void execute_main_map(rpg_t *rpg)
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

static void execute_quests(rpg_t *rpg)
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

static void drink_flask(rpg_t *rpg)
{
    rpg->all_events.mouse.right = false;
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_ATTACK) {
        remove_item_inventory(rpg, SP_FLASK_ATTACK);
        rpg->player_stats.damage += 1;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_SPEED) {
        remove_item_inventory(rpg, SP_FLASK_SPEED);
        rpg->player_stats.speed += 1;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_DRUNK) {
        sfClock_restart(rpg->player_stats.drunk_time);
        rpg->player_stats.speed += SPEED_DRUNK;
        remove_item_inventory(rpg, SP_FLASK_DRUNK);
        rpg->player_stats.drunk = true;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
}

static void execute_base(rpg_t *rpg)
{
    sfFloatRect co = {-20, -20, 40, 40};
    if (check_collision_npc(rpg, SP_BED_SLEEP, co) && rpg->all_events.enter) {
        rpg->all_events.enter = false;
        button_bed_saving(rpg);
    }
}

static void execute_taverne(rpg_t *rpg)
{
    if (check_collision_npc(rpg, SP_NPC_SELLER,
    (sfFloatRect){-15, -15, 60, 30}) && rpg->all_events.enter &&
    rpg->quest[QUEST_SELLER].active == -1) {
        put_shop_gui(rpg);
        rpg->all_events.enter = false;
    }
}

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
