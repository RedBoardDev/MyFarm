/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_sprite_house.c
*/

#include "../../include/rpg.h"

void init_spritesheets_rooms(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/house/background_base.png",
    &spritesheet[SP_BACKGROUND_SC_BASE],
    (init_sprite_t){{577 + 700 / 2, 671 + 394 / 2}, {1, 1}, {0, 0, 700, 394},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/background_jail.png",
    &spritesheet[SP_BACKGROUND_JAIL],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 640, 360},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/donjons/background_grotte.png",
    &spritesheet[SP_BACKGROUND_GROTTE],
    (init_sprite_t){{444, 1196 + 20}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/donjons/background_cemetery.png",
    &spritesheet[SP_BACKGROUND_CEMETERY],
    (init_sprite_t){{384, 1581}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/house/Background_tipi.png",
    &spritesheet[SP_BACKGROUND_TENTE],
    (init_sprite_t){{190, 417 - 190}, {1, 1}, {0, 0, 768, 432},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}
