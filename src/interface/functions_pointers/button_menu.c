/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** button_menu.c
*/

#include "../../../include/rpg.h"

void how_play(rpg_t *rpg)
{
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_HOW_PLAY);
}

void display_custom_skins(rpg_t *rpg)
{
    reset_all_players(rpg);
    sfSprite_setColor(rpg->spritesheet[SP_BACKGROUND_SC_MENU].sprite,
    (sfColor){255, 255, 255, 180});
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_CUSTOM_SKINS);
}

void button_option_main_menu(rpg_t *rpg)
{
    toggle_spritesheet_scene(rpg, false, SC_MENU);
    toggle_spritesheet_scene(rpg, true, SC_OPTION);
    set_view(rpg, rpg->screen[SC_OPTION].view_pos);
}
