/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** move_player_view.c
*/

#include "../../include/rpg.h"

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
