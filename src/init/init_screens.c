/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_screens.c
*/

#include "../../include/rpg.h"

const int screen_menu[] = {SP_BACKGROUND_SC_MENU, SP_PLAY, SP_QUIT, SP_CUSTOM,
SP_MONKEY, SP_CURSOR, -1};
const int screen_custom[] = {SP_BACKGROUND_SC_MENU, SP_PLAYER_BLUE,
SP_PLAYER_BROWN, SP_PLAYER_CYAN, SP_PLAYER_GREEN, SP_PLAYER_GREY,
SP_PLAYER_PINK, SP_PLAYER_RED, SP_PLAYER_YELLOW, SP_PLAY, SP_CURSOR, -1};
const int screen_game[] = {SP_BACKGROUND_SC_MAIN_MAP, SELECTED_PLAYER, -1};
const int screen_base[] = {SP_BACKGROUND_SC_BASE, SELECTED_PLAYER, SP_CURSOR, -1};
const int screen_inventory[] = {SP_INVENTORY, SP_CURSOR, -1};
const int screen_jail[] = {SP_BACKGROUND_JAIL, SELECTED_PLAYER, SP_CURSOR, -1};
const int screen_how_play[] = {SP_BACKGROUND_HOW_PLAY, SP_BACK, SP_CURSOR, -1};
const int screen_victory_cemetery[] = {SP_BACKGROUND_CEMETERY, SELECTED_PLAYER,
SP_BOSS_EXECUTIONER, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,
SP_LIFE_BAR_BOSS, SP_BACKGROUND_VICRORY_GROTTE, SP_NEXT_GROTTE, SP_CURSOR, -1};
const int screen_pause_menu[] = {SP_RESUME, SP_OPTION, SP_LEAVE_GAME, \
SP_CURSOR, -1};
const int screen_option_menu[] = {SP_BACKGROUND_HOW_PLAY, SP_SOUND,
SP_SOUND_SLIDER, SP_SOUNDBAR, SP_BOX_BUTTON, SP_SOUND_MUSIC,
SP_SOUND_SLIDER_MUSIC, SP_SOUNDBAR_MUSIC, SP_BOX_BUTTON_MUSIC, SP_BACK,
SP_CURSOR, SP_ARROW_LEFT, SP_ARROW_RIGHT, SP_BUTTON_ON_OFF_LUM,
SP_BUTTON_ON_OFF_FPS, SP_BUTTON_SCREEN, -1};
const int screen_grotte[] = {SP_BACKGROUND_GROTTE, SELECTED_PLAYER,
SP_BOSS_GOLEM, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,
SP_LIFE_BAR_BOSS, SP_CURSOR, -1};
const int screen_cemetery[] = {SP_BACKGROUND_CEMETERY, SELECTED_PLAYER,
SP_BOSS_EXECUTIONER, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,
SP_LIFE_BAR_BOSS, -1};
const int screen_tente[] = {SP_BACKGROUND_TENTE, SELECTED_PLAYER, SP_NPC_SOLDIER, -1};

void init_screens(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t) * NBR_SC);
    rpg->screen[SC_MENU] = (screen_t){.active = true,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 1, screen_menu};
    rpg->screen[SC_CUSTOM_SKINS] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 1, screen_custom};
    rpg->screen[SC_MAIN_MAP] = (screen_t){.active = false,
    .view_pos = {SPAWN_X, SPAWN_Y}, .view_zoom = 0.4, screen_game};
    rpg->screen[SC_BASE] = (screen_t){.active = false,
    .view_pos = {SPAWN_X - 30, SPAWN_Y - 170}, .view_zoom = 0.4, screen_base};
    rpg->screen[SC_INVENTORY] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 0.4, screen_inventory};
    rpg->screen[SC_GROTTE] = (screen_t){.active = false,
    .view_pos = {444, 1196 + 20}, .view_zoom = 0.4, screen_grotte};
    rpg->screen[SC_VICTORY_CEMETERY] = (screen_t){.active = false,
    .view_pos = {384, 1581}, .view_zoom = 0.4, screen_victory_cemetery};
    rpg->screen[SC_HOW_PLAY] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 1, screen_how_play};
    rpg->screen[SC_PAUSE] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 0.4, screen_pause_menu};
    rpg->screen[SC_OPTION] = (screen_t){.active = false,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 1, screen_option_menu};
    rpg->screen[SC_CEMETERY] = (screen_t){.active = false,
    .view_pos = {384, 1581}, .view_zoom = 0.4, screen_cemetery};

    rpg->screen[SC_TENTE] = (screen_t){.active = false,
    .view_pos = {SPAWN_X - 760, SPAWN_Y - 770}, .view_zoom = 0.32, screen_tente};

    for (int i = 0; i < NBR_SC; ++i)
        rpg->screen[i].clock = sfClock_create();
}
