/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_main_map.c
*/

#include "../../include/rpg.h"

void init_main_map(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/main_map.png",
    &spritesheet[SP_BACKGROUND_SC_MAIN_MAP],
    begin, (init_sprite_t){{WIDTH / 2, WIDTH / 2}, {1, 1}, {0, 0, 1920, 1920},
    false, false});
}
