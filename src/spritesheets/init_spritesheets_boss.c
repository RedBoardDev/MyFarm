/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** init_spritesheets_boss.c
*/

#include "../../include/rpg.h"

void init_bosses(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/boss/executioner.png",
    &spritesheet[SP_BOSS_EXECUTIONER],
    (init_sprite_t){{444, 1196 + 100}, {1.5, 1.5}, {0, 0, 100, 100},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});

    set_one_sprite("assets/img/boss/victory_grotte.png",
    &spritesheet[SP_BACKGROUND_VICRORY_GROTTE],
    (init_sprite_t){{444, 1196}, {0.5, 0.5}, {0, 0, 1200, 675},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/boss/button_next_grotte.png",
    &spritesheet[SP_NEXT_GROTTE],
    (init_sprite_t){{444 + 148, 1196 + 110}, {0.5, 0.5}, {0, 0, 254, 87},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
}
