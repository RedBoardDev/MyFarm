/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** key_released.c
*/

#include "../../include/rpg.h"

void events_key_released_arrows(sfEvent event, events_t *all_events)
{
    if (sfKeyRight == event.key.code)
        all_events->right = false;
    if (sfKeyLeft == event.key.code)
        all_events->left = false;
    if (sfKeyUp == event.key.code)
        all_events->up = false;
    if (sfKeyDown == event.key.code)
        all_events->down = false;
    if (sfKeyPageUp == event.key.code)
        all_events->page_up = false;
    if (sfKeyPageDown == event.key.code)
        all_events->page_down = false;
}

void events_key_released_letters(sfEvent event, events_t *all_events)
{
    if (sfKeyZ == event.key.code)
        all_events->z = false;
    if (sfKeyS == event.key.code)
        all_events->s = false;
    if (sfKeyQ == event.key.code)
        all_events->q = false;
    if (sfKeyD == event.key.code)
        all_events->d = false;
    if (sfKeyE == event.key.code)
        all_events->e = false;
    if (sfKeyC == event.key.code)
        all_events->c = false;
}

void events_key_released(sfEvent event, events_t *all_events)
{
    if (sfKeySpace == event.key.code)
        all_events->space = false;
    if (sfKeyLControl == event.key.code || sfKeyRControl == event.key.code)
        all_events->ctrl = false;
    if (sfKeyTab == event.key.code)
        all_events->tab = false;
    if (sfKeyEnter == event.key.code)
        all_events->enter = false;
    if (sfKeyEscape == event.key.code)
        all_events->escape = false;
    events_key_released_arrows(event, all_events);
    events_key_released_letters(event, all_events);
}
