/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../include/rpg.h"

extern int screen_game[];
extern int screen_base[];
extern int screen_jail[];
extern int screen_grotte[];

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
    sfClock_getElapsedTime(rpg->spritesheet[rpg->skin].c_anim).microseconds;
    if (time_player >= 200000) {
        rpg->spritesheet[rpg->skin].rect.left += 48;
        sfClock_restart(rpg->spritesheet[rpg->skin].c_anim);
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

void die(rpg_t *rpg)
{
    init_all_events(&rpg->all_events);
    rpg->player_stats.incr_pos.x = 0;
    rpg->player_stats.incr_pos.y = 0;
    rpg->player_stats.speed = 1.0;
    rpg->player_stats.life = 20.0;
    move_life_bar(rpg, rpg->player_stats.life * 5);
    rpg->begin.view.center = rpg->screen[SC_MAIN_MAP].view_pos;
    rpg->screen[SC_GROTTE].active = false;
    rpg->screen[SC_MAIN_MAP].active = true;
    toggle_spritesheet_scene(rpg, false, screen_grotte, rpg->spritesheet);
    toggle_spritesheet_scene(rpg, true, screen_game, rpg->spritesheet);
    rpg->begin.view.center = (sfVector2f){SPAWN_X, SPAWN_Y};
    rpg->spritesheet[rpg->skin].pos = (sfVector2f){SPAWN_X, SPAWN_Y};
}

void big_loop(rpg_t *rpg)
{
    my_events(rpg);
    move_all_fps_independant(rpg);
    if (!rpg->screen[SC_CUSTOM_SKINS].active)
        animate_player(rpg);
    if (rpg->screen[SC_CUSTOM_SKINS].active)
        animate_selected_skin(rpg);
    toggle_inventory(rpg);
    if (rpg->screen[SC_GROTTE].active && rpg->all_events.page_down && rpg->player_stats.life > 0) {
        --rpg->player_stats.life;
        rpg->all_events.page_down = false;
        move_life_bar(rpg, rpg->player_stats.life * 5);
    }
    if (rpg->screen[SC_GROTTE].active && rpg->all_events.page_up && rpg->player_stats.life < 20) {
        ++rpg->player_stats.life;
        rpg->all_events.page_up = false;
        move_life_bar(rpg, rpg->player_stats.life * 5);
    }
    if (rpg->screen[SC_GROTTE].active && rpg->player_stats.life == 0)
        die(rpg);
    // if (rpg->screen[SC_MENU].active)
    //     show_cursor(rpg->begin.window);
    // else
    //     hide_cursor(rpg->begin.window);
    if (rpg->screen[SC_MENU].active || rpg->screen[SC_CUSTOM_SKINS].active)
        set_view(rpg, rpg->screen[SC_MENU].view_pos);
    check_click_buttons(rpg);
    draw_all(rpg);
}

void myrpg(void)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));

    init_all(rpg);
    if (!rpg->begin.window || !rpg->begin.framebuffer)
        return;
    sfWindow_setFramerateLimit((sfWindow *)rpg->begin.window, 120);
    rpg->begin.fps.clock = sfClock_create();
    play_sound(rpg->sound.sound_list[SOUND_MENU].sound, rpg->sound.volume);
    while (sfRenderWindow_isOpen(rpg->begin.window)) {
        clean_window(&rpg->begin, sfBlack);
        big_loop(rpg);
    }
    destroy_all(rpg);
}
