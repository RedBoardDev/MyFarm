/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** minimap.c
*/

#include "../../include/rpg.h"

static void move_layer_minimap(rpg_t *rpg, float zoom)
{
    sfColor c = {255, 255, 255, 100};
    sfFloatRect map_rect =
    sfSprite_getGlobalBounds(rpg->spritesheet[SP_MINIMAP].sprite);
    sfVector2f scale = {0.58 * zoom * (zoom + 0.6) * (zoom + 0.6),
    0.58 * zoom * (zoom + 0.6) * (zoom + 0.6)};
    sfVector2f pos = {map_rect.left + (rpg->begin.view.center.x / 6.6 * zoom),
    map_rect.top + (rpg->begin.view.center.y / 6.6 * zoom)};
    sfSprite_setColor(rpg->spritesheet[SP_MINIMAP_LAYER].sprite, c);
    sfSprite_setScale(rpg->spritesheet[SP_MINIMAP_LAYER].sprite, scale);
    rpg->spritesheet[SP_MINIMAP_LAYER].pos = pos;
}

void move_minimap(rpg_t *rpg)
{
    float zoom = get_zoom(rpg->begin.view.view);
    sfVector2f pos = {rpg->begin.view.center.x + ((WIDTH / 2) * zoom) - (150 *
    zoom), rpg->begin.view.center.y - ((HEIGHT / 2) * zoom) + (150 * zoom)};
    sfVector2f scale = {1.45 * zoom, 1.45 * zoom};

    rpg->spritesheet[SP_MINIMAP].pos = pos;
    sfSprite_setScale(rpg->spritesheet[SP_MINIMAP].sprite, scale);
    move_layer_minimap(rpg, zoom);
}
