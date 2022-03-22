/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** mouse.c
*/

#include "../../include/rpg.h"

void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code)
        all_events->mouse.left = true;
    if (sfMouseRight == event.key.code)
        all_events->mouse.right = true;
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = true;
}

void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events)
{
    if (sfMouseLeft == event.key.code) {
        all_events->mouse.left = false;
        all_events->mouse.left_released = true;
    }
    if (sfMouseRight == event.key.code)
        all_events->mouse.right = false;
    if (sfMouseMiddle == event.key.code)
        all_events->mouse_wheel.click = false;
}

void events_scroll_wheel(sfEvent event, events_t *all_events)
{
    if (event.mouseWheelScroll.delta > 0)
        all_events->mouse_wheel.up = true;
    else
        all_events->mouse_wheel.up = false;
    if (event.mouseWheelScroll.delta < 0)
        all_events->mouse_wheel.down = true;
    else
        all_events->mouse_wheel.down = false;
}

void events_mouse_moved(sfEvent event, events_t *all_events)
{
    if (all_events->mouse.pos.x != event.mouseMove.x)
        all_events->mouse.move_x = all_events->mouse.pos.x - event.mouseMove.x;
    if (all_events->mouse.pos.y != event.mouseMove.y)
        all_events->mouse.move_y = all_events->mouse.pos.y - event.mouseMove.y;
}
