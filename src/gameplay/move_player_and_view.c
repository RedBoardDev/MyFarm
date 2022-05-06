/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_player_and_view.c
*/

#include "../../include/rpg.h"

void set_limits_player(rpg_t *rpg)
{
    if (rpg->spritesheet[rpg->player_stats.skin].pos.x < 17)
        rpg->spritesheet[rpg->player_stats.skin].pos.x = 17;
    if (rpg->spritesheet[rpg->player_stats.skin].pos.y < 22)
        rpg->spritesheet[rpg->player_stats.skin].pos.y = 22;
    if (rpg->spritesheet[rpg->player_stats.skin].pos.x > 1905)
        rpg->spritesheet[rpg->player_stats.skin].pos.x = 1905;
    if (rpg->spritesheet[rpg->player_stats.skin].pos.y > 1895)
        rpg->spritesheet[rpg->player_stats.skin].pos.y = 1895;
}

void move_player_jump(rpg_t *rpg)
{
    int floor = rpg->screen[SC_GROTTE].active ? 1330 : 1698;
    int max_jump = floor - 130;

    if (rpg->all_events.space
    && rpg->spritesheet[rpg->player_stats.skin].pos.y >= floor)
        rpg->player_stats.incr_pos.y = -3;
    if (!rpg->all_events.space
    && rpg->spritesheet[rpg->player_stats.skin].pos.y < floor)
        rpg->player_stats.incr_pos.y = 3;
    rpg->spritesheet[rpg->player_stats.skin].pos.y +=
    rpg->player_stats.incr_pos.y;
    if (rpg->spritesheet[rpg->player_stats.skin].pos.y <= max_jump)
        rpg->player_stats.incr_pos.y = 3;
    if (rpg->spritesheet[rpg->player_stats.skin].pos.y >= floor)
        rpg->player_stats.incr_pos.y = 0;
}

static void move_player_and_view3(rpg_t *rpg)
{
    if ((rpg->screen[SC_BASE].active || rpg->screen[SC_TENTE].active ||
    rpg->screen[SC_TAVERNE].active || rpg->screen[SC_JAIL].active)
    && !rpg->screen[SC_GUI_SHOP].active &&
    !rpg->spritesheet[SP_MINIMAP_TAVERNE].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
        teleport_player_scene(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos);
    }
}

static void move_player_and_view2(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active && !rpg->screen[SC_INVENTORY].active
    && !rpg->screen[SC_PAUSE].active && !rpg->screen[SC_GUI_SHOP].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos, true);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos, true);
        rpg->screen[SC_MAIN_MAP].view_pos = rpg->begin.view.center;
        teleport_player_scene(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos);
    }
    move_player_and_view3(rpg);
}

void move_player_and_view(rpg_t *rpg)
{
    if (check_status_dialog(rpg->quest))
        return;
    move_player_and_view2(rpg);
    if (rpg->screen[SC_CEMETERY].active) {
        move_player_jump(rpg);
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
    }
    if (rpg->screen[SC_GROTTE].active)
        move_player_jump(rpg);
    set_limits_player(rpg);
    set_view(rpg, rpg->begin.view.center);
    move_minimap(rpg);
}
