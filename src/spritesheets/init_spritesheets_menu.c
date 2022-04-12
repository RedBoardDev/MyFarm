/*
** EPITECH PROJECT, 2021
** B-MUL-200-MLH-2-1-myrpg-martin.d-herouville
** File description:
** init_sprites_menu.C
*/

#include "../../include/rpg.h"

void init_buttons_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/button_play.png", &spritesheet[SP_PLAY],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28}, {1, 1}, {0, 0, 156, 94},
    .clickable = true, .active = true, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_custom.png", &spritesheet[SP_CUSTOM],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 1.84}, {1, 1}, {0, 0, 494, 94},
    .clickable = true, .active = true, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_quit.png", &spritesheet[SP_QUIT],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 1.54}, {1, 1}, {0, 0, 404, 94},
    .clickable = true, .active = true, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_back.png", &spritesheet[SP_BACK],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28}, {1, 1}, {0, 0, 156, 94},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
}

void init_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/background_menu.png",
    &spritesheet[SP_BACKGROUND_SC_MENU],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = true, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/background_how_play.png",
    &spritesheet[SP_BACKGROUND_HOW_PLAY],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/monkey.png", &spritesheet[SP_MONKEY],
    (init_sprite_t){{WIDTH / 1.36, HEIGHT / 1.32}, {1, 1}, {0, 0, 128, 147},
    .clickable = true, .active = true, .change_sprite_on_mouse = true});
    init_buttons_menu(spritesheet);
}

void init_soundbox(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/soundbox/sound_click.png",
    &spritesheet[SP_SOUND_CLICK],
    (init_sprite_t){{WIDTH - 120, 40}, {0.1, 0.1}, {0, 0, 541, 541},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/soundbox_potentio.png",
    &spritesheet[SP_SOUND_POTENTIO],
    (init_sprite_t){{WIDTH - 275, 100}, {0.1, 0.1}, {0, 0, 3620, 541},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/soundbox_select.png",
    &spritesheet[SP_SOUND_SELECT],
    (init_sprite_t){{WIDTH - 312, 100}, {0.06, 0.06}, {0, 0, 541, 541},
    .clickable = true, .active = false, .change_sprite_on_mouse = false});
}

void init_inventory(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/inventory.png", &spritesheet[SP_INVENTORY],
    (init_sprite_t){{WIDTH/2, HEIGHT/2}, {1, 1}, {0, 0, 750, 314},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}
