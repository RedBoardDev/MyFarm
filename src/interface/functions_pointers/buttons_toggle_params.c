/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** buttons_toggle_params.c
*/

#include "../../../include/rpg.h"

void button_toggle_fullscreen(rpg_t *rpg)
{
    if (rpg->params.fullscreen) {
        rpg->params.fullscreen = false;
        re_create_window(rpg, false);
        rpg->spritesheet[SP_BUTTON_SCREEN].rect.left =
        rpg->spritesheet[SP_BUTTON_SCREEN].rect.width;
    } else {
        rpg->params.fullscreen = true;
        re_create_window(rpg, true);
        rpg->spritesheet[SP_BUTTON_SCREEN].rect.left = 0;
    }
}

void button_toggle_dark_mode(rpg_t *rpg)
{
    if (rpg->params.dark_mode) {
        rpg->params.dark_mode = false;
        rpg->spritesheet[SP_BUTTON_ON_OFF_LUM].rect.left =
        rpg->spritesheet[SP_BUTTON_ON_OFF_LUM].rect.width;
    } else {
        rpg->params.dark_mode = true;
        rpg->spritesheet[SP_BUTTON_ON_OFF_LUM].rect.left = 0;
    }
}

void button_toggle_show_fps(rpg_t *rpg)
{
    if (rpg->params.show_fps) {
        rpg->params.show_fps = false;
        rpg->spritesheet[SP_BUTTON_ON_OFF_FPS].rect.left =
        rpg->spritesheet[SP_BUTTON_ON_OFF_FPS].rect.width;
    } else {
        rpg->params.show_fps = true;
        rpg->spritesheet[SP_BUTTON_ON_OFF_FPS].rect.left = 0;
    }
}

void button_left_fps(rpg_t *rpg)
{
    --rpg->params.index_fps;
}

void button_right_fps(rpg_t *rpg)
{
    ++rpg->params.index_fps;
}
