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
    (init_sprite_t){{400, 400}, {0.9, 0.9}, {0, 0, 45, 42},
    true, false, false});
    set_one_sprite("assets/img/item/patato.png", &spritesheet[SP_ITEM_PATATO],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 39, 30}, true, false, false});
    set_one_sprite("assets/img/item/tomate.png", &spritesheet[SP_ITEM_TOMATE],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 36, 36}, true, false, false});
    set_one_sprite("assets/img/item/bucket_milk.png",
    &spritesheet[SP_ITEM_MILK],
    (init_sprite_t){{SPAWN_X + 480, SPAWN_Y + 50}, {0.10, 0.10},
    {0, 0, 227, 244}, true, false, false});
    set_one_sprite("assets/img/item/beets.png", &spritesheet[SP_ITEM_BEETS],
    (init_sprite_t){{100, 100}, {1, 1}, {0, 0, 33, 48}, true, false, false});
    set_one_sprite("assets/img/item/prisoners_pee.png",
    &spritesheet[SP_ITEM_PRISONER_PEE],
    (init_sprite_t){{1130, 1670}, {1, 1}, {0, 0, 22, 18}, true, false, false});
}

void init_spritesheets_flask(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/item/armor.png",
    &spritesheet[SP_ITEM_ARMOR],
    (init_sprite_t){{100, 100}, {1.5, 1.5}, {0, 0, 26, 26}, true, false,
    false});
    set_one_sprite("assets/img/item/flask_attack.png",
    &spritesheet[SP_FLASK_ATTACK],
    (init_sprite_t){{100, 100}, {0.7, 0.7}, {0, 0, 64, 64}, true,
    false, false});
    set_one_sprite("assets/img/item/flask_speed.png",
    &spritesheet[SP_FLASK_SPEED],
    (init_sprite_t){{100, 100}, {0.7, 0.7}, {0, 0, 64, 64}, true, false,
    false});
    set_one_sprite("assets/img/item/flask_drunk.png",
    &spritesheet[SP_FLASK_DRUNK],
    (init_sprite_t){{100, 100}, {0.7, 0.7}, {0, 0, 64, 64}, true, false,
    false});
    set_one_sprite("assets/img/item/flask_revive.png",
    &spritesheet[SP_FLASK_REVIVE],
    (init_sprite_t){{100, 100}, {0.7, 0.7}, {0, 0, 64, 64}, true, false,
    false});
}

void init_spritesheets_armed(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/item/shovel.png", &spritesheet[SP_ITEM_SHOVEL],
    (init_sprite_t){{100, 100}, {3, 3}, {0, 0, 13, 13}, true, false, false});
    set_one_sprite("assets/img/item/hoe.png", &spritesheet[SP_ITEM_HOE],
    (init_sprite_t){{100, 100}, {2, 2}, {0, 0, 14, 12}, true, false, false});
    set_one_sprite("assets/img/item/pickaxe.png", &spritesheet[SP_ITEM_PICKAXE],
    (init_sprite_t){{100, 100}, {0.6, 0.6}, {0, 0, 48, 48},
    true, false, false});
    set_one_sprite("assets/img/item/fishing_rod.png",
    &spritesheet[SP_ITEM_FISHING_ROD],
    (init_sprite_t){{150, 150}, {2, 2}, {0, 0, 16, 15}, true, false, false});
    set_one_sprite("assets/img/item/sword.png", &spritesheet[SP_ITEM_SWORD],
    (init_sprite_t){{100, 100}, {2, 2}, {0, 0, 14, 14}, true, false, false});
}
