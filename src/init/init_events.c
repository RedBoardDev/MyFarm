/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_events.c
*/

#include "../../include/rpg.h"

static void init_all_events_mouse(events_t *events)
{
    events->mouse.left = false;
    events->mouse.left_released = false;
    events->mouse.right = false;
    events->mouse.move_x = 0;
    events->mouse.move_y = 0;
    events->mouse.pos = (sfVector2i){0, 0};
    events->mouse.pos_view = (sfVector2f){0, 0};
    events->mouse_wheel.up = false;
    events->mouse_wheel.down = false;
    events->mouse_wheel.click = false;
}

void init_all_events(events_t *events)
{
    events->left = false;
    events->right = false;
    events->up = false;
    events->down = false;
    events->page_up = false;
    events->page_down = false;
    events->z = false;
    events->q = false;
    events->s = false;
    events->d = false;
    events->e = false;
    events->c = false;
    events->escape = false;
    events->space = false;
    events->ctrl = false;
    events->tab = false;
    events->enter = false;
    init_all_events_mouse(events);
}
