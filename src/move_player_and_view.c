/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** move_player_and_view.c
*/

#include "../include/rpg.h"
extern int screen_game[];
extern int screen_base[];
extern int screen_jail[];

void set_limits_player(rpg_t *rpg)
{
    if (rpg->spritesheet[S_PLAYER].pos.x < 17)
        rpg->spritesheet[S_PLAYER].pos.x = 17;
    if (rpg->spritesheet[S_PLAYER].pos.y < -391)
        rpg->spritesheet[S_PLAYER].pos.y = -391;
    if (rpg->spritesheet[S_PLAYER].pos.x > 1905)
        rpg->spritesheet[S_PLAYER].pos.x = 1905;
    if (rpg->spritesheet[S_PLAYER].pos.y > 1471)
        rpg->spritesheet[S_PLAYER].pos.y = 1471;
}

void move_player_and_view_horizontal(rpg_t *rpg)
{
    sfColor color;

    if (rpg->all_events.right) {
        color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
        spritesheet[S_PLAYER].pos.x + 2, rpg->spritesheet[S_PLAYER].pos.y});
        if (rpg->spritesheet[S_PLAYER].pos.x > 385 &&
        rpg->begin.view.center.x < 1535 && color.r != 255)
            rpg->begin.view.center.x += 2;
        if (color.r != 255)
            rpg->spritesheet[S_PLAYER].pos.x += 2;
    }
    if (rpg->all_events.left) {
        color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
        spritesheet[S_PLAYER].pos.x - 2, rpg->spritesheet[S_PLAYER].pos.y});
        if (rpg->spritesheet[S_PLAYER].pos.x < 1535 &&
        rpg->begin.view.center.x > 385 && color.r != 255)
            rpg->begin.view.center.x -= 2;
        if (color.r != 255)
            rpg->spritesheet[S_PLAYER].pos.x -= 2;
    }
}

void move_player_and_view_vertical(rpg_t *rpg)
{
    sfColor color;

    if (rpg->all_events.up) {
        color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
        spritesheet[S_PLAYER].pos.x, rpg->spritesheet[S_PLAYER].pos.y - 2});
        if (rpg->spritesheet[S_PLAYER].pos.y < 1282 &&
        rpg->begin.view.center.y > -203 && color.r != 255)
            rpg->begin.view.center.y -= 2;
        if (color.r != 255)
            rpg->spritesheet[S_PLAYER].pos.y -= 2;
    }
    if (rpg->all_events.down) {
        color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
        spritesheet[S_PLAYER].pos.x, rpg->spritesheet[S_PLAYER].pos.y + 2});
        if (rpg->spritesheet[S_PLAYER].pos.y > -203 &&
        rpg->begin.view.center.y < 1282 && color.r != 255)
            rpg->begin.view.center.y += 2;
        if (color.r != 255)
            rpg->spritesheet[S_PLAYER].pos.y += 2;
    }
}

void teleport_player_scene(rpg_t *rpg)
{
    sfColor color;

    color = get_color_from_player(rpg->map_colors, (sfVector2f){rpg->
    spritesheet[S_PLAYER].pos.x, rpg->spritesheet[S_PLAYER].pos.y});
    if (color.b == M_BASE) {
        if (rpg->screen[GAME].active) {
            active_spritesheet_scene(false, screen_game, rpg->spritesheet);
            active_spritesheet_scene(true, screen_base, rpg->spritesheet);
        } else {
            active_spritesheet_scene(true, screen_game, rpg->spritesheet);
            active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        }
        return;
    }
    if (color.b == M_JAIL) {
        if (rpg->screen[GAME].active) {
            active_spritesheet_scene(false, screen_game, rpg->spritesheet);
            active_spritesheet_scene(true, screen_base, rpg->spritesheet);
        } else {
            active_spritesheet_scene(true, screen_game, rpg->spritesheet);
            active_spritesheet_scene(false, screen_base, rpg->spritesheet);
        }
        return;
    }
}

void move_player_and_view(rpg_t *rpg)
{
    move_player_and_view_horizontal(rpg);
    move_player_and_view_vertical(rpg);
    set_limits_player(rpg);
    teleport_player_scene(rpg);
    set_view(rpg, rpg->begin.view.center);
}
