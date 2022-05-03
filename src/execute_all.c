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
    menu_pause(rpg);
}

static void execute_all_menus(rpg_t *rpg)
{
    set_size_cursor(rpg, 0.15);
    set_view(rpg, rpg->screen[SC_MENU].view_pos);
}

void execute_main_map(rpg_t *rpg)
{
    collition_pee(rpg);
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
}
