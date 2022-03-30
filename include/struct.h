/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** struct.h
*/

#ifndef STRUCT_H
    #define STRUCT_H

    #include <SFML/Graphics/Export.h>
    #include <SFML/Graphics.h>
    #include <SFML/Audio.h>
    #include <sys/stat.h>
    #include <stdbool.h>
    #include <stdlib.h>
    #include <unistd.h>
    #include <fcntl.h>
    #include <stdio.h>
    #include <stdio.h>
    #include <math.h>

typedef struct {
    sfVector2f pos;
    sfVector2f scale;
    sfIntRect rect;
    bool clickable;
    bool active;
} init_sprite_t;

typedef struct {
    char *str;
    int size;
    sfVector2f pos;
    sfColor color;
} init_text_t;

typedef struct {
    sfClock *clock;
    float timer;
} fps_t;

typedef struct {
    sfView *view;
    sfVector2f center;
} view_t;

typedef struct {
    sfRenderWindow *window;
    sfUint8 *framebuffer;
    sfTexture *texture;
    sfSprite *sprite;
    view_t view;
    fps_t fps;
} beginning_t;

typedef struct {
    bool left;
    bool left_released;
    bool right;
    int move_x;
    int move_y;
    sfVector2i pos;
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
    bool escape;
    bool space;
    bool ctrl;
    bool tab;
    bool enter;
    mouse_t mouse;
    mouse_wheel_t mouse_wheel;
} events_t;

typedef struct {
    bool active;
    float view_zoom;
    sfVector2f view_pos;
} screen_t;

typedef struct {
    bool active;
    bool clickable;
    int *a_screen;
    sfVector2f pos;
    sfIntRect rect;
    sfSprite *sprite;
    sfTexture *texture;
} spritesheet_t;

typedef struct {
    beginning_t begin;
    events_t all_events;
    spritesheet_t *spritesheet;
    screen_t *screen;
} rpg_t;

#endif
