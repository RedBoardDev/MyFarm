/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../../include/rpg.h"

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

void init_all(rpg_t *rpg)
{
    rpg->begin.fps.clock = sfClock_create();
    rpg->begin.fps.timer = 0;
    rpg->all_events = init_all_events();
    rpg->sound.volume = 0; //SET SOUND AT THE FINAL PUSH
    init_imgs(rpg);
    init_screens(rpg);
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_view(rpg);
    init_spritesheets(rpg->spritesheet, &rpg->begin);
    init_sounds(rpg);
    init_csfml(&rpg->begin);
}
