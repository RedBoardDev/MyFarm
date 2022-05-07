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
    bool no_sound;
    bool help;
    char *filepath;
    bool ok;
} entry_program_t;

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
    int speaker;
    spritesheet_t bubulle;
} quest_t;

typedef struct {
    bool active;
    bool done;
    char *text_string;
    sfText *text;
} quests_inv_t;

typedef struct {
    sfText *skill_speed;
    sfText *skill_resistance;
    sfText *skill_strength;
} skills_inv_t;

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
    bool toggle_notif;
    int inc_pos;
    sfVector2f offset_hide;
    sfText *text;
} notif_t;

typedef struct {
    int cutscene_nbr;
    int status_move;
    sfClock *clock;
    sfVector2f pos_player;
    spritesheet_t *spritesheet;
} cutscenes_t;

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
    quests_inv_t *quests_inv;
    skills_inv_t skills_inv;
    params_t params;
    notif_t notif;
    cutscenes_t cutscenes;
} rpg_t;

#endif
