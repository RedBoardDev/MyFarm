/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_sprites_menu_options.c
*/

#include "../../include/rpg.h"

void init_buttons_option_menu_4(spritesheet_t *spritesheet)
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

void init_buttons_option_menu_3(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/menu/button_fs_wd.png",
    &spritesheet[SP_BUTTON_SCREEN], (init_sprite_t){{WIDTH / 1.4,
    HEIGHT / 1.252}, {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true,
    .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/show_fps.png",
    &spritesheet[SP_BUTTON_ON_OFF_FPS], (init_sprite_t){{WIDTH / 1.4,
    HEIGHT / 2.05}, {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true,
    .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/light_dark_mode.png",
    &spritesheet[SP_BUTTON_ON_OFF_LUM], (init_sprite_t){{WIDTH / 1.4,
    HEIGHT / 1.55}, {0.7, 0.7}, {0, 0, 400, 200}, .clickable = true,
    .active = false, .change_sprite_on_mouse = true});
    set_one_sprite("assets/img/menu/button_arrow_right.png",
    &spritesheet[SP_ARROW_RIGHT], (init_sprite_t){{WIDTH / 1.19, HEIGHT / 3},
    {0.7, 0.7}, {0, 0, 200, 200}, .clickable = true, .active = false,
    .change_sprite_on_mouse = true});
    init_buttons_option_menu_4(spritesheet);
}

void init_buttons_option_menu_2(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/soundbox/SoundButton.png",
    &spritesheet[SP_SOUND_SLIDER_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT
    / 2}, {0.55, 0.55}, {0, 0, 155, 154}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/SoundBar.png",
    &spritesheet[SP_SOUNDBAR_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 2},
    {0.35, 0.35}, {0, 0, 1516, 121}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/Sound_music.png",
    &spritesheet[SP_SOUND_MUSIC], (init_sprite_t){{WIDTH / 30, HEIGHT / 2},
    {0.3, 0.3}, {0, 0, 300, 260}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/box_button.png",
    &spritesheet[SP_BOX_BUTTON_MUSIC], (init_sprite_t){{WIDTH / 4.3, HEIGHT
    / 2}, {0.65, 0.65}, {0, 0, 1000, 200}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    init_buttons_option_menu_3(spritesheet);
}

void init_buttons_option_menu(spritesheet_t *spritesheet)
{
    set_one_sprite("assets/img/soundbox/SoundButton.png",
    &spritesheet[SP_SOUND_SLIDER_EFFECT], (init_sprite_t){{WIDTH / 4.3,
    HEIGHT / 3}, {0.55, 0.55}, {0, 0, 155, 154}, .clickable = true,
    .active = false, .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/SoundBar.png",
    &spritesheet[SP_SOUNDBAR_EFFECT], (init_sprite_t){{WIDTH / 4.3, HEIGHT / 3},
    {0.35, 0.35}, {0, 0, 1516, 121}, .clickable = false, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/soundbox/Sound.png",
    &spritesheet[SP_SOUND_EFFECT], (init_sprite_t){{WIDTH / 30, HEIGHT / 3},
    {0.3, 0.3}, {0, 0, 300, 260}, .clickable = true, .active = false,
    .change_sprite_on_mouse = false});
    set_one_sprite("assets/img/menu/box_button.png",
    &spritesheet[SP_BOX_BUTTON_EFFECT], (init_sprite_t){{WIDTH / 4.3,
    HEIGHT / 3}, {0.65, 0.65}, {0, 0, 1000, 200}, .clickable = false,
    .active = false, .change_sprite_on_mouse = false});
    init_buttons_option_menu_2(spritesheet);
}
