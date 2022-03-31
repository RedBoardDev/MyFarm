/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../include/rpg.h"

events_t init_all_events(void)
{
    return ((events_t){.left = false, .right = false, .up = false,
    .down = false, .page_up = false, .page_down = false, .z = false, .s = false,
    .q = false, .d = false, .escape = false,
    .space = false, .ctrl = false, .tab = false, .enter = false, .mouse =
    {.left = false, .left_released = false, .right = false, .move_x = 0,
    .move_y = 0, .pos = {0, 0}}, .mouse_wheel = {.up = false, .down = false,
    .click = false}});
}

void init_screen(rpg_t *rpg)
{
    rpg->screen = malloc(sizeof(screen_t) * NBR_SCREENS);
    rpg->screen[SC_MENU] = (screen_t){.active = true,
    .view_pos = {WIDTH / 2, HEIGHT / 2}, .view_zoom = 0};
    rpg->screen[SC_MAIN_MAP] = (screen_t){.active = false,
    .view_pos = {1090, 613}, .view_zoom = 0.4};
    rpg->screen[SC_BASE] = (screen_t){.active = false,
    .view_pos = {1090, 613}, .view_zoom = 0.4};
}

void init_all(rpg_t *rpg)
{
    rpg->begin.fps.timer = 0;
    rpg->begin.fps.clock = sfClock_create();
    rpg->all_events = init_all_events();
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    rpg->begin.view.view = sfView_createFromRect((sfFloatRect)
    {0, 0, 1920, 1080});
    rpg->begin.view.center = (sfVector2f){SPAWN_X, SPAWN_Y};
    sfView_zoom(rpg->begin.view.view , 0.4);
    rpg->begin.view.view =
    sfView_createFromRect((sfFloatRect){0, 0, 1920, 1080});
    init_csfml(&rpg->begin);
    init_spritesheets(rpg->spritesheet, &rpg->begin);
    init_screen(rpg);
}
