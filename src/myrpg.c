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
    // printf("%d - %d\n", rpg->all_events.mouse.pos.x, rpg->all_events.mouse.pos.y);
    my_events(rpg);
    move_all_fps_independant(rpg);
    if (!rpg->screen[SC_CUSTOM_SKINS].active)
        animate_player(rpg);
    if (rpg->screen[SC_CUSTOM_SKINS].active)
        animate_selected_skin(rpg);
    manage_inventory(rpg);
    if (rpg->screen[SC_GROTTE].active) {
        if (rpg->all_events.page_down && rpg->boss_stats.life > 0) {
            --rpg->boss_stats.life;
            rpg->all_events.page_down = false;
        }
        move_life_bar(rpg, rpg->player_stats.life * 5);
        move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
        animate_boss(rpg);
    }
    if (rpg->screen[SC_GROTTE].active && rpg->all_events.page_up
    && rpg->boss_stats.life < 20) {
        ++rpg->boss_stats.life;
        rpg->all_events.page_up = false;
        move_life_bar(rpg, rpg->player_stats.life * 5);
    }
    if (rpg->screen[SC_GROTTE].active && rpg->player_stats.life <= 0)
        die(rpg);
    if (rpg->screen[SC_MENU].active || rpg->screen[SC_CUSTOM_SKINS].active)
        set_view(rpg, rpg->screen[SC_MENU].view_pos);
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
