/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_screens.c
*/

#include "../../include/rpg.h"

const int screen_menu[] = {SP_BACKGROUND_SC_MENU, SP_PLAY, SP_QUIT, SP_CUSTOM, -1};
const int screen_custom[] = {SP_BACKGROUND_SC_MENU, SP_PLAYER_BLUE,
SP_PLAYER_BROWN, SP_PLAYER_CYAN, SP_PLAYER_GREEN, SP_PLAYER_GREY,
SP_PLAYER_PINK, SP_PLAYER_RED, SP_PLAYER_YELLOW, SP_PLAY, -1};
const int screen_game[] = {SP_BACKGROUND_SC_MAIN_MAP, -2, -1};
const int screen_base[] = {SP_BACKGROUND_SC_BASE, -2, -1};
const int screen_jail[] = {SP_BACKGROUND_JAIL, -2, -1};

void init_screens(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t) * NBR_SCREENS);
    rpg->screen[SC_MENU] = (screen_t){.active = true,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 0};
    rpg->screen[SC_CUSTOM_SKINS] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 0};
    rpg->screen[SC_MAIN_MAP] = (screen_t){.active = false,
    .view_pos = {SPAWN_X, SPAWN_Y}, .view_zoom = 0.4};
    rpg->screen[SC_BASE] = (screen_t){.active = false,
    .view_pos = {SPAWN_X - 30, SPAWN_Y - 170}, .view_zoom = 0.4};
}
