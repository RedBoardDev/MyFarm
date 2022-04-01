/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_player_and_view.c
*/

#include "../../include/rpg.h"

void set_limits_player(rpg_t *rpg)
{
    if (rpg->spritesheet[SP_PLAYER].pos.x < 17)
        rpg->spritesheet[SP_PLAYER].pos.x = 17;
    if (rpg->spritesheet[SP_PLAYER].pos.y < 22)
        rpg->spritesheet[SP_PLAYER].pos.y = 22;
    if (rpg->spritesheet[SP_PLAYER].pos.x > 1905)
        rpg->spritesheet[SP_PLAYER].pos.x = 1905;
    if (rpg->spritesheet[SP_PLAYER].pos.y > 1895)
        rpg->spritesheet[SP_PLAYER].pos.y = 1895;
}

void move_player_and_view_horizontal(rpg_t *rpg, sfImage *image, sfVector2f pos_player, bool move_view)
{
    sfColor color;

    if (rpg->all_events.right) {
        color = get_color_from_player(image, (sfVector2f){pos_player.x + 2, pos_player.y});
        if (rpg->spritesheet[SP_PLAYER].pos.x > 385 &&
        rpg->begin.view.center.x < 1535 && color.r != 255 && move_view)
            rpg->begin.view.center.x += 2;
        if (color.r != 255)
            rpg->spritesheet[SP_PLAYER].pos.x += 2;
    }
    if (rpg->all_events.left) {
        color = get_color_from_player(image, (sfVector2f){pos_player.x - 2, pos_player.y});
        if (rpg->spritesheet[SP_PLAYER].pos.x < 1535 &&
        rpg->begin.view.center.x > 385 && color.r != 255 && move_view)
            rpg->begin.view.center.x -= 2;
        if (color.r != 255)
            rpg->spritesheet[SP_PLAYER].pos.x -= 2;
    }
}

void move_player_and_view_vertical(rpg_t *rpg, sfImage *image, sfVector2f pos_player, bool move_view)
{
    sfColor color;

    if (rpg->all_events.up) {
        color = get_color_from_player(image, (sfVector2f){pos_player.x, pos_player.y - 2});
        if (rpg->spritesheet[SP_PLAYER].pos.y < 1920 - 217 &&
        rpg->begin.view.center.y > 216 && color.r != 255 && move_view)
            rpg->begin.view.center.y -= 2;
        if (color.r != 255)
            rpg->spritesheet[SP_PLAYER].pos.y -= 2;
    }
    if (rpg->all_events.down) {
        color = get_color_from_player(image, (sfVector2f){pos_player.x, pos_player.y + 2});
        if (rpg->spritesheet[SP_PLAYER].pos.y > 216 &&
        rpg->begin.view.center.y < 1920 - 217 && color.r != 255 && move_view)
            rpg->begin.view.center.y += 2;
        if (color.r != 255)
            rpg->spritesheet[SP_PLAYER].pos.y += 2;
    }
}

void move_player_and_view(rpg_t *rpg)
{
    if (rpg->screen[SC_MAIN_MAP].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.main_map, rpg->spritesheet[SP_PLAYER].pos, true);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.main_map, rpg->spritesheet[SP_PLAYER].pos, true);
        rpg->screen[SC_MAIN_MAP].view_pos = rpg->begin.view.center;
        teleport_player_scene(rpg, rpg->imgs_colors.main_map, rpg->spritesheet[SP_PLAYER].pos);
    }
    if (rpg->screen[SC_BASE].active) {
        move_player_and_view_horizontal(rpg, rpg->imgs_colors.backgrounds, rpg->spritesheet[SP_PLAYER].pos, false);
        move_player_and_view_vertical(rpg, rpg->imgs_colors.backgrounds, rpg->spritesheet[SP_PLAYER].pos, false);
        teleport_player_scene(rpg, rpg->imgs_colors.backgrounds, rpg->spritesheet[SP_PLAYER].pos);

    }
    set_limits_player(rpg);
    set_view(rpg, rpg->begin.view.center);
}
