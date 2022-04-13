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

void big_loop(rpg_t *rpg)
{
    my_events(rpg);
    move_all_fps_independant(rpg);
    execute_all(rpg);
    check_click_buttons(rpg);
    check_mouse_on_all_buttons(rpg);
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
    toggle_cursor(rpg->begin.window, false);
    while (sfRenderWindow_isOpen(rpg->begin.window)) {
        clean_window(&rpg->begin, sfBlack);
        big_loop(rpg);
    }
    destroy_all(rpg);
}
