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
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_custom.png", &spritesheet[SP_CUSTOM],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28 + 115 * 2},
    {1, 1}, {0, 0, 494, 94},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_quit.png", &spritesheet[SP_QUIT],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28 + 115 * 3}, {1, 1},
    {0, 0, 404, 94},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/options_main_menu.png",
    &spritesheet[SP_OPTIONS_MAIN_MENU],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2.28 + 115}, {1, 1},
    {0, 0, 255, 94}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_back.png", &spritesheet[SP_BACK],
    (init_sprite_t){{100, 70}, {1, 1}, {0, 0, 156, 94},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
}

void init_buttons_pause_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/menu_resume.png",
    &spritesheet[SP_RESUME], (init_sprite_t){{WIDTH, HEIGHT},
    {0.6, 0.6}, {0, 0, 404, 94}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/menu_option.png",
    &spritesheet[SP_OPTION], (init_sprite_t){{WIDTH, HEIGHT},
    {0.6, 0.6}, {0, 0, 404, 94}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/menu_leave.png",
    &spritesheet[SP_LEAVE_GAME], (init_sprite_t){{WIDTH, HEIGHT},
    {0.6, 0.6}, {0, 0, 404, 94}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
}

void init_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/background_menu.png",
    &spritesheet[SP_BACKGROUND_SC_MENU],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/background_how_play.png",
    &spritesheet[SP_BACKGROUND_HOW_PLAY],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/background_options.png",
    &spritesheet[SP_BACKGROUND_OPTIONS],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 1920, 1080},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/monkey.png", &spritesheet[SP_MONKEY],
    (init_sprite_t){{WIDTH / 1.36, HEIGHT / 1.32}, {1, 1}, {0, 0, 128, 147},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    init_buttons_menu(spritesheet);
}

void init_spritesheet_inventory(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/inventory.png", &spritesheet[SP_INVENTORY],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 742, 314},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});

    set_one_sprite("assets/img/menu/box_button.png", &spritesheet[SP_NOTIF],
    (init_sprite_t){{-1000, -1000}, {0.5, 0.5}, {0, 0, 1000, 200},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}

void init_spritesheet_gui_shop(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/shop/gui_shop.png",
    &spritesheet[SP_GUI_SHOP],
    (init_sprite_t){{700, 160}, {0.8, 0.8}, {0, 0, 400, 490},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/shop/button_flask_life.png",
    &spritesheet[SP_SHOP_BUTTON1],
    (init_sprite_t){{700, 90}, {0.8, 0.8}, {0, 0, 344, 216 / 3},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/shop/button_flask_speed.png",
    &spritesheet[SP_SHOP_BUTTON2],
    (init_sprite_t){{700, 162}, {0.8, 0.8}, {0, 0, 344, 216 / 3},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/shop/button_flask_attack.png",
    &spritesheet[SP_SHOP_BUTTON3],
    (init_sprite_t){{700, 235}, {0.8, 0.8}, {0, 0, 344, 216 / 3},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/shop/button_flask_drunk.png",
    &spritesheet[SP_SHOP_BUTTON4],
    (init_sprite_t){{700, 304}, {0.8, 0.8}, {0, 0, 344, 216 / 3},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
}
