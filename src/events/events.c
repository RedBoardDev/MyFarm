/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../../include/rpg.h"

void events_key_global(sfEvent event, rpg_t *rpg)
{
    switch (event.type) {
        case sfEvtKeyPressed:
            events_key_pressed(rpg, event);
            break;
        case sfEvtKeyReleased:
            events_key_released(event, &rpg->all_events);
            break;
        case sfEvtTextEntered:
            break;
        default:
            break;
    }
}

void events_mouse_global(sfEvent event, beginning_t *begin,
events_t *all_events)
{
    switch (event.type) {
        case sfEvtMouseButtonPressed:
            events_mouse_pressed(begin, event, all_events);
            break;
        case sfEvtMouseButtonReleased:
            events_mouse_released(begin, event, all_events);
            break;
        case sfEvtMouseWheelScrolled:
            events_scroll_wheel(event, all_events);
            break;
        case sfEvtMouseMoved:
            events_mouse_moved(event, all_events);
            break;
        default:
            break;
    }
}

void my_events(rpg_t *rpg)
{
    sfEvent event;

    rpg->all_events.mouse_wheel.up = false;
    rpg->all_events.mouse_wheel.down = false;
    rpg->all_events.mouse.left_released = false;
    rpg->all_events.mouse.move_x = 0;
    rpg->all_events.mouse.move_y = 0;
    while (sfRenderWindow_pollEvent(rpg->begin.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->begin.window);
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased ||
        event.type == sfEvtTextEntered)
            events_key_global(event, rpg);
        if (event.type == sfEvtMouseButtonPressed || event.type ==
        sfEvtMouseButtonReleased || event.type == sfEvtMouseWheelScrolled ||
        event.type == sfEvtMouseMoved)
            events_mouse_global(event, &rpg->begin, &rpg->all_events);
    }
    rpg->all_events.mouse.pos =
    sfMouse_getPositionRenderWindow(rpg->begin.window);
}
