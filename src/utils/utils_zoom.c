/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_zoom.c
*/

#include "../../include/rpg.h"

void set_zoom(sfView *view, float new_zoom)
{
    sfView_reset(view, (sfFloatRect){0, 0, 1920, 1080});
    sfView_zoom(view, new_zoom);
}

float get_zoom(sfView *view)
{
    sfVector2f size = sfView_getSize(view);

    return (size.x / WIDTH);
}
