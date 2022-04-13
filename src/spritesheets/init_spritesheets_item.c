/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheets_item.c
*/

#include "../../include/rpg.h"

void init_spritesheets_food(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/item/carrot.png", &spritesheet[SP_ITEM_CARROT],
    (init_sprite_t){{400, 400}, {1, 1}, {0, 0, 45, 42}, true, false, false});
    set_one_sprite("assets/img/item/patato.png", &spritesheet[SP_ITEM_PATATO],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 39, 30}, true, false, false});
    set_one_sprite("assets/img/item/tomate.png", &spritesheet[SP_ITEM_TOMATE],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 36, 36}, true, false, false});
    set_one_sprite("assets/img/item/strawberry.png",
    &spritesheet[SP_ITEM_STRAWBERRY],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 27, 33}, true, false, false});
    set_one_sprite("assets/img/item/beets.png", &spritesheet[SP_ITEM_BEETS],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 33, 48}, true, false, false});
}

void init_spritesheets_armed(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/item/shovel.png", &spritesheet[SP_ITEM_SHOVEL],
    (init_sprite_t){{100, 100}, {15, 15}, {0, 0, 13, 13}, true, false, false});
    set_one_sprite("assets/img/item/hoe.png", &spritesheet[SP_ITEM_HOE],
    (init_sprite_t){{100, 100}, {15, 15}, {0, 0, 14, 12}, true, false, false});
    set_one_sprite("assets/img/item/martin.png", &spritesheet[SP_ITEM_HAMMER],
    (init_sprite_t){{100, 100}, {15, 15}, {0, 0, 15, 15}, true, false, false});
    set_one_sprite("assets/img/item/fishing_rod.png",
    &spritesheet[SP_ITEM_FISHING_ROD],
    (init_sprite_t){{150, 150}, {16, 15}, {0, 0, 16, 15}, true, false, false});
    set_one_sprite("assets/img/item/sword.png", &spritesheet[SP_ITEM_SWORD],
    (init_sprite_t){{100, 100}, {15, 15}, {0, 0, 14, 14}, true, false, false});
}