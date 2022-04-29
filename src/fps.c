/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** fps.c
*/

#include "../include/rpg.h"

const char *fps_settings[] = {"Uncapped", "30", "60", "120", "144", "240",
"360", NULL};

void draw_fps(rpg_t *rpg)
{
    float zoom = get_zoom(rpg->begin.view.view);
    sfVector2f pos_l = {rpg->begin.view.center.x - ((WIDTH / 2) * zoom) + (10 *
    zoom), rpg->begin.view.center.y + ((HEIGHT / 2) * zoom) - (40 * zoom)};
    sfVector2f pos = {pos_l.x + (70 * zoom), pos_l.y};
    sfVector2f scale = {0.3 * zoom, 0.3 * zoom};

    if (get_clock_time(rpg->begin.fps_disp.display_clock) >=
    SECOND_TO_MICRO(0.2)) {
        sfText_setString(rpg->begin.fps_disp.fps_text,
        my_itoa(rpg->begin.fps_disp.fps));
        sfClock_restart(rpg->begin.fps_disp.display_clock);
    }
    sfText_setPosition(rpg->begin.fps_disp.fps_text, pos);
    sfText_setScale(rpg->begin.fps_disp.fps_text, scale);
    sfText_setPosition(rpg->begin.fps_disp.legende, pos_l);
    sfText_setScale(rpg->begin.fps_disp.legende, scale);
    write_text(rpg->begin.window, rpg->begin.fps_disp.fps_text);
    write_text(rpg->begin.window, rpg->begin.fps_disp.legende);
}

void draw_text_fps_settings(rpg_t *rpg)
{
    unsigned int char_size = 0;
    sfVector2f origin = {0, 0};

    if (rpg->params.index_fps >= array_len(fps_settings))
        rpg->params.index_fps = 0;
    else if (rpg->params.index_fps < 0)
        rpg->params.index_fps = array_len(fps_settings) - 1;
    sfText_setString(rpg->params.fps_text, fps_settings[rpg->params.index_fps]);
    char_size = sfText_getCharacterSize(rpg->params.fps_text);
    origin.x = (my_strlen(fps_settings[rpg->params.index_fps]) * char_size) / 4;
    origin.y = char_size / 2;
    sfText_setOrigin(rpg->params.fps_text, origin);
    write_text(rpg->begin.window, rpg->params.fps_text);
    rpg->params.fps = my_atoi(fps_settings[rpg->params.index_fps]);
    sfRenderWindow_setFramerateLimit(rpg->begin.window, rpg->params.fps);
}

int get_fps(rpg_t *rpg)
{
    rpg->begin.fps_disp.time = get_clock_time(rpg->begin.fps_disp.clock);
    rpg->begin.fps_disp.fps = 1 / (rpg->begin.fps_disp.time / 1000000);
    sfClock_restart(rpg->begin.fps_disp.clock);
    return (rpg->begin.fps_disp.fps);
}
