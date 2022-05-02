/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include "structs_stats.h"

typedef struct {
    sfView *view;
    sfVector2f center;
} view_t;

typedef struct {
    bool active;
    sfVector2f view_pos;
    float view_zoom;
    const int *const_screen;
    sfClock *clock;
} screen_t;

typedef struct {
    bool active;
    bool clickable;
    bool change_sprite_on_mouse;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
    sfClock *c_anim;
    sfClock *c_attack;
} spritesheet_t;

typedef struct {
    sfImage *main_map;
    sfImage *backgrounds;
} images_t;

typedef struct {
    int step;
    int active;
    sfText *dialog;
    sfClock *clock_chat;
    bool speaker;
    sfVector2f pos_dialog;
    sfVector2f scale;
} quest_t;

typedef struct {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    view_t view;
    fps_inde_t fps;
    fps_disp_t fps_disp;
    const sfUint8 *pixels;
} beginning_t;

typedef struct {
    beginning_t begin;
    events_t all_events;
    spritesheet_t *spritesheet;
    images_t imgs_colors;
    screen_t *screen;
    sound_t sound;
    int index_old_s;
    player_stats_t player_stats;
    boss_stats_t boss_stats;
    quest_t *quest;
    params_t params;
} rpg_t;

#endif
