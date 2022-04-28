/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.c
*/

#include "../include/rpg.h"

int get_current_screen(rpg_t *rpg)
{
    for (int i = 0; i < NBR_SC; ++i) {
        if (rpg->screen[i].active)
            return (i);
    }
    return (-1);
}

static void move_sound_box(rpg_t *rpg)
{
    int pos_x = rpg->all_events.mouse.pos.x;

    if (!rpg->sound.volume_active)
        return;
    if (pos_x >= 200 && pos_x <= 708) {
        rpg->spritesheet[rpg->sound.volume_active].pos.x = pos_x;
        if (rpg->sound.volume_active == SP_SOUND_SLIDER_MUSIC)
            rpg->sound.volume_music = (pos_x - 200) / 5.05;
        else if (rpg->sound.volume_active == SP_SOUND_SLIDER_EFFECT)
            rpg->sound.volume_music = (pos_x - 200) / 5.05;
    }
    rpg->sound.volume_music < 0 ? rpg->sound.volume_music = 0 : 0;
    rpg->sound.volume_effect < 0 ? rpg->sound.volume_effect = 0 : 0;
}

static void big_loop(rpg_t *rpg, sfColor *oui)
{
    *oui = my_rgb(*oui);
    get_fps(rpg);
    my_events(rpg);
    if ((rpg->all_events.q || rpg->all_events.c) && rpg->all_events.ctrl)
        sfRenderWindow_close(rpg->begin.window);
    if (rpg->all_events.page_down) {
        set_zoom(rpg->begin.view.view, get_zoom(rpg->begin.view.view) + 0.1);
        rpg->all_events.page_down = false;
    }
    if (rpg->all_events.page_up) {
        set_zoom(rpg->begin.view.view, get_zoom(rpg->begin.view.view) - 0.1);
        rpg->all_events.page_up = false;
    }
    move_sound_box(rpg);
    move_all_fps_independant(rpg);
    execute_all(rpg);
    check_click_buttons(rpg);
    check_mouse_on_all_buttons(rpg);
    draw_all(rpg);
}

void myrpg(int sound)
{
    rpg_t *rpg = malloc(sizeof(rpg_t));
    sfColor oui = {255, 0, 0, 255};
    sfImage *img = sfImage_createFromFile("assets/img/logo.png");
    const sfUint8 *pixels = sfImage_getPixelsPtr(img);

    init_all(rpg);
    if (sound == 0) {
        rpg->sound.volume_music = 0;
        rpg->sound.volume_effect = 0;
    }
    if (!rpg->begin.window || !rpg->begin.framebuffer)
        return;
    sfWindow_setFramerateLimit((sfWindow *)rpg->begin.window, 0);
    sfWindow_setIcon((sfWindow *)rpg->begin.window, 512, 512, pixels);
    rpg->begin.fps.clock = sfClock_create();
    play_sound(rpg->sound.sound_list[SOUND_MENU].sound,
    rpg->sound.volume_music);
    toggle_cursor(rpg->begin.window, false);
    while (sfRenderWindow_isOpen(rpg->begin.window)) {
        clean_window(&rpg->begin, sfBlack);
        big_loop(rpg, &oui);
    }
    destroy_all(rpg);
}
