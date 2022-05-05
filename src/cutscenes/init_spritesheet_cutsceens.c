/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_spritesheet_cutsceens.c
*/

#include "../../include/rpg.h"

void init_spritehseet_cutsceens(rpg_t *rpg)
{
    rpg->cutsceens.clock = sfClock_create();
    rpg->cutsceens.spritesheet = malloc(sizeof(spritesheet_t) * NBR_CS);
    rpg->cutsceens.pos_player = (sfVector2f){-20, 880};
    set_one_sprite("assets/img/cutsceens/cut_scene_background.png",
    &rpg->cutsceens.spritesheet[CS_BEGIN_BACKGROUND],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = true, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/cutsceens/chat_bubble.png",
    &rpg->cutsceens.spritesheet[CS_BEGIN_BUBULLE],
    (init_sprite_t){{1350, 650}, {1, 1}, {0, 0, 250, 232},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}
