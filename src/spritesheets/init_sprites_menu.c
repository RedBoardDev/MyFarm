/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_sprites_menu.C
*/

#include "../../include/rpg.h"

void init_button_menu(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/menu/button_play.png",
    &spritesheet[SP_PLAY],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28}, {1, 1}, {0, 0, 156, 94},
    .clickable = true, .active = true});
    set_one_sprite("assets/img/menu/button_custom.png",
    &spritesheet[SP_CUSTOM],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 1.84}, {1, 1}, {0, 0, 494, 94},
    .clickable = true, .active = true});
    set_one_sprite("assets/img/menu/button_quit.png",
    &spritesheet[SP_QUIT],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 1.54}, {1, 1}, {0, 0, 404, 94},
    .clickable = true, .active = true});
}

void init_menu(spritesheet_t *spritesheet, beginning_t *begin)
{
    set_one_sprite("assets/img/menu/background_menu.png",
    &spritesheet[SP_BACKGROUND_SC_MENU],
    begin, (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = true});
    init_button_menu(spritesheet, begin);
}
