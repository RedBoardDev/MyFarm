/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_sprite_house.c
*/

#include "../../include/rpg.h"

void init_spritesheet_house(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/house/background_base.png",
    &spritesheet[SP_BACKGROUND_SC_BASE],
    begin, (init_sprite_t){{577 + 700 / 2, 671 + 394 / 2}, {1, 1},
    {0, 0, 700, 394}, .clickable = false, .active = false});
    set_one_sprite("assets/img/house/background_jail.png",
    &spritesheet[SP_BACKGROUND_JAIL],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 640, 360},
    .clickable = false, .active = false});
}
