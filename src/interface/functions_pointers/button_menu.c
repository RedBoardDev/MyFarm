/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu.c
*/

#include "../../../include/rpg.h"

SCREENS_INT

void how_play(rpg_t *rpg)
{
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_HOW_PLAY].sprite,
    (sfColor){255, 255, 255, 140});
    toggle_spritesheet_scene(rpg, false, screen_menu, -1);
    toggle_spritesheet_scene(rpg, true, screen_how_play, -1); // a faire (screen)
}

void set_player(rpg_t *rpg)
{
    sfSprite_setScale(rpg->spritesheet[rpg->player_stats.skin].sprite,
    (sfVector2f){0.7, 0.7});
}

void launch_game(rpg_t *rpg)
{
    rpg->spritesheet[rpg->player_stats.skin].pos =
    (sfVector2f){SPAWN_X, SPAWN_Y};
    set_player(rpg);
    sfView_zoom(rpg->begin.view.view , rpg->screen[SC_MAIN_MAP].view_zoom);
    toggle_spritesheet_scene(rpg, false, screen_menu, SC_MENU);
    toggle_spritesheet_scene(rpg, false, screen_custom, SC_CUSTOM_SKINS);
    toggle_spritesheet_scene(rpg, true, screen_game, SC_MAIN_MAP);
}

void quit_game(rpg_t *rpg)
{
    sfRenderWindow_close(rpg->begin.window);
}

void display_custom_skins(rpg_t *rpg)
{
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_SC_MENU].sprite,
    (sfColor){255, 255, 255, 180});
    toggle_spritesheet_scene(rpg, false, screen_menu, SC_MENU);
    toggle_spritesheet_scene(rpg, true, screen_custom, SC_CUSTOM_SKINS);
}
