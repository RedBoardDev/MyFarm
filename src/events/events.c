/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** events.c
*/

#include "../../include/rpg.h"

static void events_key_global(sfEvent event, rpg_t *rpg)
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

static void events_mouse_global(rpg_t *rpg, sfEvent event, events_t *all_events)
{
    switch (event.type) {
        case sfEvtMouseButtonPressed:
            events_mouse_pressed(rpg, event, all_events);
            break;
        case sfEvtMouseButtonReleased:
            events_mouse_released(rpg, event, all_events);
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

static void init_mouse(rpg_t *rpg)
{
    rpg->all_events.mouse_wheel.up = false;
    rpg->all_events.mouse_wheel.down = false;
    rpg->all_events.mouse.left_released = false;
    rpg->all_events.mouse.move_x = 0;
    rpg->all_events.mouse.move_y = 0;
}

static void scream_lost(rpg_t *rpg)
{
    sfSoundStatus st =
    sfSound_getStatus(rpg->sound.sound_list[SOUND_LOST_FOCUS].sound);

    if (st != sfPlaying)
        play_sound(rpg->sound.sound_list[SOUND_LOST_FOCUS].sound,
        rpg->sound.volume_effect);
}

void my_events(rpg_t *rpg)
{
    sfEvent event;

    init_mouse(rpg);
    while (sfRenderWindow_pollEvent(rpg->begin.window, &event)) {
        if (event.type == sfEvtClosed)
            sfRenderWindow_close(rpg->begin.window);
        if (event.type == sfEvtKeyPressed || event.type == sfEvtKeyReleased ||
        event.type == sfEvtTextEntered)
            events_key_global(event, rpg);
        if (event.type == sfEvtMouseButtonPressed || event.type ==
        sfEvtMouseButtonReleased || event.type == sfEvtMouseWheelScrolled ||
        event.type == sfEvtMouseMoved)
            events_mouse_global(rpg, event, &rpg->all_events);
        if (event.type == sfEvtLostFocus)
            scream_lost(rpg);
    }
    rpg->all_events.mouse.pos =
    sfMouse_getPositionRenderWindow(rpg->begin.window);
    rpg->all_events.mouse.pos_view = sfRenderWindow_mapPixelToCoords(
    rpg->begin.window, rpg->all_events.mouse.pos, rpg->begin.view.view);
}
