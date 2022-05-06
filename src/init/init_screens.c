/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_screens.c
*/

#include "../../include/rpg.h"

const int screen_menu[] = {SP_BACKGROUND_SC_MENU, SP_PLAY, SP_QUIT, SP_CUSTOM, \
SP_OPTIONS_MAIN_MENU, SP_MONKEY, SP_CURSOR, -1};
const int screen_custom[] = {SP_BACKGROUND_SC_MENU, SP_BACK, SP_PLAYER_BLUE, \
SP_PLAYER_BROWN, SP_PLAYER_CYAN, SP_PLAYER_GREEN, SP_PLAYER_GREY,   \
SP_PLAYER_PINK, SP_PLAYER_RED, SP_PLAYER_YELLOW, SP_PLAY, SP_CURSOR, -1};
const int screen_main_map[] = {SP_BACKGROUND_SC_MAIN_MAP, SELECTED_PLAYER,
SP_NPC_GUIDE, SP_MINIMAP, SP_MINIMAP_LAYER, SP_TOMBE, -1};
const int screen_base[] = {SP_BACKGROUND_SC_BASE, SELECTED_PLAYER,  \
SP_BED_SLEEP, SP_CURSOR, -1};
const int screen_inventory[] = {SP_INVENTORY, SP_CURSOR, -1};
const int screen_how_play[] = {SP_BACKGROUND_HOW_PLAY, SP_BACK, SP_CURSOR, -1};
const int screen_gui_shop[] = {SP_GUI_SHOP, SP_SHOP_BUTTON1, SP_SHOP_BUTTON2,
SP_SHOP_BUTTON3, SP_SHOP_BUTTON4, SP_CURSOR -1};
const int screen_pause_menu[] = {SP_RESUME, SP_OPTION, SP_LEAVE_GAME, \
SP_CURSOR, -1};
const int screen_option_menu[] = {SP_BACKGROUND_OPTIONS, SP_SOUND_EFFECT,  \
SP_SOUND_SLIDER_EFFECT, SP_SOUNDBAR_EFFECT, SP_BOX_BUTTON_EFFECT,   \
SP_SOUND_MUSIC, \
SP_SOUND_SLIDER_MUSIC, SP_SOUNDBAR_MUSIC, SP_BOX_BUTTON_MUSIC, SP_BACK, \
SP_ARROW_LEFT, SP_ARROW_RIGHT, SP_BUTTON_ON_OFF_LUM, SP_BUTTON_ON_OFF_FPS,  \
SP_BUTTON_SCREEN, SP_FPS_SELECTOR, SP_CURSOR, -1};
const int screen_victory_cemetery[] = {SP_BACKGROUND_CEMETERY, SELECTED_PLAYER,
SP_BOSS_EXECUTIONER, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,    \
SP_LIFE_BAR_BOSS, SP_BACKGROUND_VICTORY_GROTTE, SP_NEXT_GROTTE, SP_CURSOR, -1};
const int screen_victory_grotte[] = {SP_BACKGROUND_GROTTE, SELECTED_PLAYER, \
SP_BOSS_GOLEM, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,  \
SP_LIFE_BAR_BOSS, SP_BACKGROUND_VICTORY_GROTTE, SP_NEXT_GROTTE, SP_CURSOR, -1};
const int screen_grotte[] = {SP_BACKGROUND_GROTTE, SELECTED_PLAYER, \
SP_BOSS_GOLEM, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,  \
SP_LIFE_BAR_BOSS, -1};
const int screen_cemetery[] = {SP_BACKGROUND_CEMETERY, SELECTED_PLAYER, \
SP_BOSS_EXECUTIONER, SP_LIFE_BAR_BOX, SP_LIFE_BAR, SP_LIFE_BAR_BOX_BOSS,    \
SP_LIFE_BAR_BOSS, -1};
const int screen_tente[] = {SP_BACKGROUND_TENTE, SELECTED_PLAYER,   \
SP_NPC_SOLDIER, -1};
const int screen_taverne[] = {SP_BACKGROUND_TAVERNE, SELECTED_PLAYER,   \
SP_NPC_SELLER, SP_MAPS_TAVERNE, SP_CURSOR, -1};
const int screen_jail[] = {SP_BACKGROUND_JAIL, SELECTED_PLAYER, -1};

static screen_t init_one_scene(bool active, const int *const_screen,
sfVector2f view_pos, float view_zoom)
{
    screen_t screen;

    screen.active = active;
    screen.const_screen = const_screen;
    screen.view_pos = view_pos;
    screen.view_zoom = view_zoom;
    return screen;
}

static void init_screen_norme(rpg_t *rpg)
{
    rpg->screen[SC_VICTORY_GROTTE] = init_one_scene(false,
    screen_victory_grotte, (sfVector2f){444, 1196 + 20}, 0.4);
    rpg->screen[SC_GROTTE] = init_one_scene(false,
    screen_grotte, (sfVector2f){444, 1196 + 20}, 0.4);
    rpg->screen[SC_VICTORY_CEMETERY] = init_one_scene(false,
    screen_victory_cemetery, (sfVector2f){384, 1581}, 0.4);
    rpg->screen[SC_HOW_PLAY] = init_one_scene(false,
    screen_how_play, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 1);
    rpg->screen[SC_PAUSE] = init_one_scene(false,
    screen_pause_menu, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 0.4);
    rpg->screen[SC_OPTION] = init_one_scene(false,
    screen_option_menu, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 1);
    rpg->screen[SC_CEMETERY] = init_one_scene(false,
    screen_cemetery, (sfVector2f){384, 1581}, 0.4);
    rpg->screen[SC_TENTE] = init_one_scene(false,
    screen_tente, (sfVector2f){SPAWN_X - 760, SPAWN_Y - 770}, 0.32);
    rpg->screen[SC_TAVERNE] = init_one_scene(false,
    screen_taverne, (sfVector2f){850, 356 - ((432 - 50) / 2)}, 0.4);
}

void init_screens(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t) * NBR_SC);
    rpg->screen[SC_MENU] = init_one_scene(true,
    screen_menu, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 1);
    rpg->screen[SC_CUSTOM_SKINS] = init_one_scene(false,
    screen_custom, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 1);
    rpg->screen[SC_MAIN_MAP] = init_one_scene(false,
    screen_main_map, (sfVector2f){SPAWN_X, SPAWN_Y}, 0.4);
    rpg->screen[SC_BASE] = init_one_scene(false,
    screen_base, (sfVector2f){SPAWN_X - 30, SPAWN_Y - 170}, 0.4);
    rpg->screen[SC_INVENTORY] = init_one_scene(false,
    screen_inventory, (sfVector2f){WIDTH / 2, HEIGHT / 2}, 0.4);
    rpg->screen[SC_JAIL] = init_one_scene(false,
    screen_jail, (sfVector2f){1716 - 250, 1742 - 200}, 0.4);
    rpg->screen[SC_GUI_SHOP] = init_one_scene(false,
    screen_gui_shop, (sfVector2f){850, 356 - ((432 - 50) / 2)}, 0.4);
    rpg->screen[SC_CUTSCENE_BEGIN].active = false;
    init_screen_norme(rpg);
    for (int i = 0; i < NBR_SC; ++i)
        rpg->screen[i].clock = sfClock_create();
}
