/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_player_and_view_h_v.c
*/

#include "../../include/rpg.h"

static void move_player_and_view_horizontal_oui(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color = get_color_from_player(image, pos_player);
    float speed = getsp(rpg, color);
    if (rpg->all_events.right || rpg->all_events.d) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x + speed + 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x > 385 &&
        rpg->begin.view.center.x < 1535 && color.r != 255 && move_view)
            rpg->begin.view.center.x += speed;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x += speed;
    }
    if (rpg->all_events.left || rpg->all_events.q) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x - speed - 2, pos_player.y});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.x < 1535 &&
        rpg->begin.view.center.x > 385 && color.r != 255 && move_view)
            rpg->begin.view.center.x -= speed;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.x -= speed;
    }
}

void move_player_and_view_horizontal(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    move_player_and_view_horizontal_oui(rpg, image, pos_player, move_view);
    set_view(rpg, rpg->begin.view.center);
}

static void move_player_and_view_vertical_oui(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    sfColor color = get_color_from_player(image, pos_player);
    float speed = getsp(rpg, color);
    if (rpg->all_events.up || rpg->all_events.z) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y - speed - 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y < 1920 - 217 &&
        rpg->begin.view.center.y > 216 && color.r != 255 && move_view)
            rpg->begin.view.center.y -= speed;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y -= speed;
    }
    if (rpg->all_events.down || rpg->all_events.s) {
        color = get_color_from_player(image,
        (sfVector2f){pos_player.x, pos_player.y + speed + 2});
        if (rpg->spritesheet[rpg->player_stats.skin].pos.y > 216 &&
        rpg->begin.view.center.y < 1920 - 217 && color.r != 255 && move_view)
            rpg->begin.view.center.y += speed;
        if (color.r != 255)
            rpg->spritesheet[rpg->player_stats.skin].pos.y += speed;
    }
}

void move_player_and_view_vertical(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view)
{
    move_player_and_view_vertical_oui(rpg, image, pos_player, move_view);
    set_view(rpg, rpg->begin.view.center);
}
