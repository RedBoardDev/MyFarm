/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** key.c
*/

#include "../../include/rpg.h"

void events_key_pressed_arrows(sfEvent event, events_t *all_events)
{
    if (sfKeyRight == event.key.code)
        all_events->right = true;
    if (sfKeyLeft == event.key.code)
        all_events->left = true;
    if (sfKeyUp == event.key.code)
        all_events->up = true;
    if (sfKeyDown == event.key.code)
        all_events->down = true;
    if (sfKeyPageUp == event.key.code)
        all_events->page_up = true;
    if (sfKeyPageDown == event.key.code)
        all_events->page_down = true;
    if (sfKeyTab == event.key.code)
        all_events->tab = true;
}

void events_key_pressed_letters(sfEvent event, events_t *all_events)
{
    if (sfKeyZ == event.key.code)
        all_events->z = true;
    if (sfKeyS == event.key.code)
        all_events->s = true;
    if (sfKeyQ == event.key.code)
        all_events->q = true;
    if (sfKeyD == event.key.code)
        all_events->d = true;
    if (sfKeyE == event.key.code)
        all_events->e = true;
    if (sfKeyC == event.key.code)
        all_events->c = true;
    if (sfKeySpace == event.key.code)
        all_events->space = true;
    if (sfKeySpace == event.key.code)
        all_events->space = true;
}

void events_key_pressed_not_letters(rpg_t *rpg, sfEvent event)
{
    if (sfKeyEscape == event.key.code)
        rpg->all_events.escape = true;
    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        rpg->all_events.ctrl = true;
    if (sfKeyEnter == event.key.code)
        rpg->all_events.enter = true;
}

void events_key_pressed(rpg_t *rpg, sfEvent event)
{
    events_key_pressed_not_letters(rpg, event);
    events_key_pressed_arrows(event, &rpg->all_events);
    events_key_pressed_letters(event, &rpg->all_events);
}
