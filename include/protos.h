/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** protos.h
*/

#ifndef PROTOS_H
    #define PROTOS_H

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
    #include "struct.h"

void myrpg(void);

// events
void my_events(beginning_t *begin, events_t *all_events);
void events_key_pressed(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void events_mouse_moved(sfEvent event, events_t *all_events);

// init
void init_all(rpg_t *rpg);

// draw simple
void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius,
sfColor color);
void my_draw_rectangle(sfUint8 *framebuffer, sfIntRect rect, sfColor color);
void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b,
sfColor color);
void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color);
void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color);

// utils
void clean_window(beginning_t *begin, sfColor color);
void init_csfml(beginning_t *beginning);
void destroy_all(beginning_t *begin);
int my_rand(int min, int max);
bool check_mouse_on_one_button(sfVector2i pos, sfFloatRect collision);

// utils sprites
void set_one_sprite(char *filename, spritesheet_t *spritesheet,
beginning_t *begin, init_sprite_t init_sprite);
void write_text(beginning_t *begin, init_text_t struct_text);
void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos);

// lib sound
void stop_sound(sfSound *sound);
void play_sound(sfSound *sound, float volume);
void destroy_sound(sfSound *sound);
sfSound *create_sound(char *filepath);

#endif
