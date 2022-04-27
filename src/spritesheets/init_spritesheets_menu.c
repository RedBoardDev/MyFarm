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
    (init_sprite_t){{100, 70}, {1, 1}, {0, 0, 156, 94},
    .clickable = true, .active = false, .change_sprite_on_mouse = true});
}

void init_buttuns_pause_menu(spritesheet_t *spritesheet)
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

void init_buttuns_option_menu_4(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/button_arrow_left.png",
    &spritesheet[SP_ARROW_LEFT], (init_sprite_t){{WIDTH / 1.7, HEIGHT / 3},
    {0.7, 0.7}, {0, 0, 200, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/fps_selector.png",
    &spritesheet[SP_FPS_SELECTOR], (init_sprite_t){{WIDTH / 1.4, HEIGHT / 3},
    {0.7, 0.7}, {0, 0, 400, 200}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
}

void init_buttuns_option_menu_3(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/button_fs_wd.png",
    &spritesheet[SP_BUTTON_SCREEN], (init_sprite_t){{WIDTH / 1.4, HEIGHT / 1.252},
    {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/show_fps.png",
    &spritesheet[SP_BUTTON_ON_OFF_FPS], (init_sprite_t){{WIDTH / 1.4, HEIGHT / 2.05},
    {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/light_dark_mode.png",
    &spritesheet[SP_BUTTON_ON_OFF_LUM], (init_sprite_t){{WIDTH / 1.4, HEIGHT / 1.55},
    {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_arrow_right.png",
    &spritesheet[SP_ARROW_RIGHT], (init_sprite_t){{WIDTH / 1.19, HEIGHT / 3},
    {0.7, 0.7}, {0, 0, 200, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    init_buttuns_option_menu_4(spritesheet);
}

void init_buttuns_option_menu_2(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/SoundButton.png",
    &spritesheet[SP_SOUND_SLIDER_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 2},
    {0.55, 0.55}, {0, 0, 155, 154}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/SoundBar.png",
    &spritesheet[SP_SOUNDBAR_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 2},
    {0.35, 0.35}, {0, 0, 1516, 121}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/Sound.png",
    &spritesheet[SP_SOUND_MUSIC], (init_sprite_t){{WIDTH / 30, HEIGHT / 2},
    {0.3, 0.3}, {0, 0, 300, 260}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/box_button.png",
    &spritesheet[SP_BOX_BUTTON_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 2},
    {0.65, 0.65}, {0, 0, 1000, 200}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    init_buttuns_option_menu_3(spritesheet);
}

void init_buttuns_option_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/SoundButton.png",
    &spritesheet[SP_SOUND_SLIDER], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 3},
    {0.55, 0.55}, {0, 0, 155, 154}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/SoundBar.png",
    &spritesheet[SP_SOUNDBAR], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 3},
    {0.35, 0.35}, {0, 0, 1516, 121}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/Sound.png",
    &spritesheet[SP_SOUND], (init_sprite_t){{WIDTH / 30, HEIGHT / 3},
    {0.3, 0.3}, {0, 0, 300, 260}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/box_button.png",
    &spritesheet[SP_BOX_BUTTON], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 3},
    {0.65, 0.65}, {0, 0, 1000, 200}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    init_buttuns_option_menu_2(spritesheet);
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

void init_spritesheet_inventory(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/inventory.png", &spritesheet[SP_INVENTORY],
    (init_sprite_t){{WIDTH / 2, HEIGHT / 2}, {1, 1}, {0, 0, 742, 314},
    .clickable = false, .active = false, .change_sprite_on_mouse = false});
}
