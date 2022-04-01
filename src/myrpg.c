/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../include/rpg.h"

void draw_sfImage(sfRenderWindow *window, sfImage *image, sfVector2f pos, sfIntRect rect)
{
    sfTexture *texture = sfTexture_createFromImage(image, NULL);
    sfSprite *sprite = sfSprite_create();
    sfImage_createMaskFromColor(image, (sfColor){0, 0, 0, 100}, 100);
    sfSprite_setPosition(sprite, pos);
    sfSprite_setTexture(sprite, texture, sfFalse);
    sfSprite_setTextureRect(sprite, rect);
    sfRenderWindow_drawSprite(window, sprite, NULL);
}

void draw_spritesheets(beginning_t *begin, spritesheet_t *spritesheet)
{
    for (int i = 0; i < NBR_SP; ++i)
        if (spritesheet[i].active)
            draw_one_sprite(begin, spritesheet[i].sprite, spritesheet[i].rect,
            spritesheet[i].pos);
}

sfColor get_color_from_player(sfImage *image, sfVector2f pos)
{
    return (sfImage_getPixel(image, pos.x, pos.y + 15));
}

void animate_selected_skin(rpg_t *rpg)
{
    float time_player =
    sfClock_getElapsedTime(rpg->spritesheet[rpg->skin].clock).microseconds;
    if (time_player >= 200000) {
        rpg->spritesheet[rpg->skin].rect.left += 48;
        sfClock_restart(rpg->spritesheet[rpg->skin].clock);
    }
    if (rpg->spritesheet[rpg->skin].rect.left >= 192)
        rpg->spritesheet[rpg->skin].rect.left = 0;
}

void draw_all(rpg_t *rpg)
{
    sfSprite_setTexture(rpg->begin.sprite, rpg->begin.texture, sfFalse);
    sfTexture_updateFromPixels(rpg->begin.texture,
    rpg->begin.framebuffer, WIDTH, HEIGHT, 0, 0);
    sfRenderWindow_drawSprite(rpg->begin.window,
    rpg->begin.sprite, NULL);
    draw_spritesheets(&rpg->begin, rpg->spritesheet);
    sfRenderWindow_display(rpg->begin.window);
}

void big_loop(rpg_t *rpg)
{
    my_events(&rpg->begin, &rpg->all_events);
    move_all_fps_independant(rpg);
    if (!rpg->screen[SC_CUSTOM_SKINS].active)
        animate_player(rpg);
    if (rpg->screen[SC_CUSTOM_SKINS].active)
        animate_selected_skin(rpg);
    if (rpg->screen[SC_MENU].active || rpg->screen[SC_CUSTOM_SKINS].active) {
        set_view(rpg, rpg->screen[SC_MENU].view_pos);
        manage_menu(rpg);
    }
    check_click_buttons(rpg);
    draw_all(rpg);
}

void myrpg(void)
{
    rpg_t rpg;

    init_all(&rpg);
    if (!rpg.begin.window || !rpg.begin.framebuffer)
        return;
    sfWindow_setFramerateLimit((sfWindow *)rpg.begin.window, 120);
    rpg.begin.fps.clock = sfClock_create();
    play_sound(rpg.sound.sound_list[SOUND_MENU].sound, rpg.sound.volume);
    while (sfRenderWindow_isOpen(rpg.begin.window)) {
        clean_window(&rpg.begin, sfBlack);
        big_loop(&rpg);
    }
    destroy_all(&rpg.begin);
}
