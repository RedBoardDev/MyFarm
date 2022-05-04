/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../include/rpg.h"

void init_main_map(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/main_map.png",
    &spritesheet[SP_BACKGROUND_SC_MAIN_MAP],
    (init_sprite_t){{WIDTH / 2, WIDTH / 2}, {1, 1}, {0, 0, 1920, 1920},
    false, false, false});
    set_one_sprite("assets/img/minimap.png",
    &spritesheet[SP_MINIMAP],
    (init_sprite_t){{WIDTH / 2, WIDTH / 2}, {0.58, 0.58}, {0, 0, 200, 200},
    false, false, false});
    set_one_sprite("assets/img/map_taverne.png",
    &spritesheet[SP_MINIMAP_TAVERNE],
    (init_sprite_t){{850, 356 - ((432 - 50) / 2)}, {0.5, 0.5}, {0, 0, 800, 600},
    false, false, false});
    set_one_sprite("assets/img/minimap_layer.png",
    &spritesheet[SP_MINIMAP_LAYER],
    (init_sprite_t){{WIDTH / 2, WIDTH / 2}, {0.58, 0.58}, {0, 0, 200, 112},
    false, false, false});
}
