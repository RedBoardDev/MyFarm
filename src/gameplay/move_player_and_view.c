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

void move_player_and_view_horizontal(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color;

    if (rpg->all_events.right || rpg->all_events.d) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x + 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x > 385 &&
        rpg->begin.view.center.x < 1535 && color.r != 255 && move_view)
            rpg->begin.view.center.x += SPEED_PLAYER;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x += SPEED_PLAYER;
    }
    if (rpg->all_events.left || rpg->all_events.q) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x - 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x < 1535 &&
        rpg->begin.view.center.x > 385 && color.r != 255 && move_view)
            rpg->begin.view.center.x -= SPEED_PLAYER;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x -= SPEED_PLAYER;
    }
}

void move_player_and_view_vertical(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color;

    if (rpg->all_events.up || rpg->all_events.z) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y - 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y < 1920 - 217 &&
        rpg->begin.view.center.y > 216 && color.r != 255 && move_view)
            rpg->begin.view.center.y -= SPEED_PLAYER;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y -= SPEED_PLAYER;
    }
    if (rpg->all_events.down || rpg->all_events.s) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y + 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y > 216 &&
        rpg->begin.view.center.y < 1920 - 217 && color.r != 255 && move_view)
            rpg->begin.view.center.y += SPEED_PLAYER;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y += SPEED_PLAYER;
    }
}

void move_player_jump(rpg_t *rpg)
{
    int floor = 1330;
    int max_jump = 1200;

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

void move_player_and_view(rpg_t *rpg)
{
    if (check_status_dialog(rpg->quest))
        return;
    if (rpg->screen[SC_MAIN_MAP].active && !rpg->screen[SC_INVENTORY].active &&
    !rpg->screen[SC_PAUSE].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos, true);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos, true);
        rpg->screen[SC_MAIN_MAP].view_pos = rpg->begin.view.center;
        teleport_player_scene(rpg, rpg->imgs_colors.main_map,
        rpg->spritesheet[rpg->player_stats.skin].pos);
    }
    if (rpg->screen[SC_BASE].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
        teleport_player_scene(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos);
    }
    if (rpg->screen[SC_GROTTE].active) {
        move_player_jump(rpg);
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.backgrounds,
        rpg->spritesheet[rpg->player_stats.skin].pos, false);
    }
    set_limits_player(rpg);
    set_view(rpg, rpg->begin.view.center);
}
