/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_sprite_house.c
*/

#include "../../include/rpg.h"

static void init_spritesheets_rooms_norme(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/donjons/background_cemetery.png",
    &spritesheet[SP_BACKGROUND_CEMETERY],
    (init_sprite_t){{384, 1581}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/Background_tipi.png",
    &spritesheet[SP_BACKGROUND_TENTE],
    (init_sprite_t){{190, 417 - 190}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/background_taverne.png",
    &spritesheet[SP_BACKGROUND_TAVERNE],
    (init_sprite_t){{850, 356 - ((432 - 50) / 2)}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/maps_taverne.png",
    &spritesheet[SP_MAPS_TAVERNE],
    (init_sprite_t){{701, 236}, {1, 1}, {0, 0, 56, 34},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});
}

void init_spritesheets_rooms(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/house/background_base.png",
    &spritesheet[SP_BACKGROUND_SC_BASE],
    (init_sprite_t){{577 + 700 / 2, 671 + 394 / 2}, {1, 1}, {0, 0, 700, 394},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/bed_sleep.png",
    &spritesheet[SP_BED_SLEEP],
    (init_sprite_t){{1164, 800}, {1, 1}, {0, 0, 96 / 2, 72},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/background_jail.png",
    &spritesheet[SP_BACKGROUND_JAIL],
    (init_sprite_t){{1716 - 250, 1742 - 200}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/donjons/background_grotte.png",
    &spritesheet[SP_BACKGROUND_GROTTE],
    (init_sprite_t){{444, 1196 + 20}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    init_spritesheets_rooms_norme(spritesheet);
}
