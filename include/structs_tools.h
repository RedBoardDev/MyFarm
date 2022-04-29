/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** struct.h
*/

#ifndef STRUCTS_TOOLS_H
    #define STRUCTS_TOOLS_H

    #include "structs_utils.h"

typedef struct {
    sfClock *clock;
    float timer;
} fps_inde_t;

typedef struct {
    sfText *fps_text;
    sfText *legende;
    sfClock *clock;
    sfClock *display_clock;
    float time;
    int fps;
} fps_disp_t;

typedef struct {
    bool left;
    bool left_released;
    bool right;
    int move_x;
    int move_y;
    sfVector2i pos;
    sfVector2f pos_view;
} mouse_t;

typedef struct {
    bool up;
    bool down;
    bool click;
} mouse_wheel_t;

typedef struct {
    bool left;
    bool right;
    bool up;
    bool down;
    bool page_up;
    bool page_down;
    bool z;
    bool q;
    bool s;
    bool d;
    bool e;
    bool c;
    bool escape;
    bool space;
    bool ctrl;
    bool tab;
    bool enter;
    mouse_t mouse;
    mouse_wheel_t mouse_wheel;
} events_t;

typedef struct {
    bool loop;
    sfSound *sound;
    sfSoundBuffer *sound_buffer;
} sound_list_t;

typedef struct {
    sound_list_t *sound_list;
    int volume_active;
    float volume_music;
    float volume_music_backup;
    float volume_effect;
    float volume_effect_backup;
} sound_t;

typedef struct {
    bool fullscreen;
    bool show_fps;
    bool dark_mode;
    int fps;
    int index_fps;
    sfText *fps_text;
} params_t;

#endif
