/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_item.c
*/

#include "../../include/rpg.h"

void init_spritesheets_food(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/item/rake.png", &spritesheet[SP_LIFE_BAR],
    begin, (init_sprite_t){{444 - 320, 1196 - 197}, {0.25, 0.25},
    {0, 0, 451, 121}, false, false});
}

void init_spritesheets_armed(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/item/shovel.png", &spritesheet[SP_ITEM_SHOVEL],
    begin, (init_sprite_t){{100 ,100}, {0.25, 0.25},
    {0, 0, 130, 130}, true, false});
}
