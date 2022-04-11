/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu.c
*/

#include "../../../include/rpg.h"
extern int screen_menu[];
extern int screen_game[];
extern int screen_custom[];
extern int screen_how_play[];

void how_play(rpg_t *rpg)
{
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_HOW_PLAY].sprite,
    (sfColor){255, 255, 255, 140});
    toggle_spritesheet_scene(rpg, false, screen_menu, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, true, screen_how_play, rpg->spritesheet);
}

void set_player(rpg_t *rpg)
{
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){0.7, 0.7});
}

void launch_game(rpg_t *rpg)
{
    rpg->screen[SC_MENU].active = false;
    rpg->screen[SC_CUSTOM_SKINS].active = false;
    rpg->screen[SC_MAIN_MAP].active = true;
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
    set_player(rpg);
    sfView_zoom(rpg->begin.view.view , rpg->screen[SC_MAIN_MAP].view_zoom);
    toggle_spritesheet_scene(rpg, false, screen_menu, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, false, screen_custom, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, true, screen_game, rpg->spritesheet);
}

void quit_game(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->begin.window);
}

void display_custom_skins(rpg_t *rpg)
{
    rpg->screen[SC_MENU].active = false;
    rpg->screen[SC_CUSTOM_SKINS].active = true;
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_SC_MENU].sprite,
    (sfColor){255, 255, 255, 180});
    toggle_spritesheet_scene(rpg, false, screen_menu, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, true, screen_custom, rpg->spritesheet);
}
