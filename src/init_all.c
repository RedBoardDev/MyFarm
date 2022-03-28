/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../include/rpg.h"

void init_all(rpg_t *rpg)
{
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SPRITE);
    init_csfml(&rpg->begin);
    init_spritesheets(rpg->spritesheet, &rpg->begin);
}

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
