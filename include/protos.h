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
void my_exit(rpg_t *rpg);
void manage_menu(rpg_t *rpg);
void teleport_player_scene(rpg_t *rpg, sfImage *image, sfVector2f pos_player);

// events
void my_events(rpg_t *rpg);
void events_key_pressed(rpg_t *rpg, sfEvent event);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_mouse_released(beginning_t *begin, sfEvent event,
events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void events_mouse_moved(sfEvent event, events_t *all_events);

//interface
void check_click_buttons(rpg_t *rpg);
void launch_game(rpg_t *rpg);
void quit_game(rpg_t *rpg);
void skin_blue(rpg_t *rpg);
void skin_brown(rpg_t *rpg);
void skin_cyan(rpg_t *rpg);
void skin_green(rpg_t *rpg);
void skin_grey(rpg_t *rpg);
void skin_pink(rpg_t *rpg);
void skin_red(rpg_t *rpg);
void skin_yellow(rpg_t *rpg);
void display_custom_skins(rpg_t *rpg);

// init
void init_all(rpg_t *rpg);
void init_imgs(rpg_t *rpg);
void init_main_map(spritesheet_t *spritesheet, beginning_t *begin);
void init_screens(rpg_t *rpg);
void init_sounds(rpg_t *rpg);
void init_soundbox(spritesheet_t *spritesheet, beginning_t *begin);
void init_menu(spritesheet_t *spritesheet, beginning_t *begin);
void init_spritesheets_rooms(spritesheet_t *spritesheet, beginning_t *begin);
void init_spritesheets(spritesheet_t *spritesheet, beginning_t *begin);
void init_view(rpg_t *rpg);
void init_inventory(spritesheet_t *spritesheet, beginning_t *begin);
void init_all_events(events_t *events);
void init_spritesheets_armed(spritesheet_t *spritesheet, beginning_t *begin);

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
void move_life_bar(rpg_t *rpg, int percentage);

// utils sprites
void set_one_sprite(char *filename, spritesheet_t *spritesheet,
beginning_t *begin, init_sprite_t init_sprite);
void write_text(beginning_t *begin, init_text_t struct_text);
void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos);
void toggle_spritesheet_scene(rpg_t *rpg, bool status, int *screen_i,
spritesheet_t *spritesheet);

// lib sound
void stop_sound(sfSound *sound);
void play_sound(sfSound *sound, float volume);
void create_sound(char *filepath, bool loop, sound_list_t *sound_list);
void destroy_sound(sfSound *sound, sfSoundBuffer *sound_buffer);

//view
void set_view(rpg_t *rpg, sfVector2f view_pos);

//move_object
void move_player(rpg_t *rpg);
void move_player_and_view(rpg_t *rpg);
void move_all_fps_independant(rpg_t *rpg);
sfColor get_color_from_player(sfImage *image, sfVector2f pos);
void animate_player(rpg_t *rpg);
void draw_sfImage(sfRenderWindow *window, sfImage *image, sfVector2f pos, sfIntRect rect);

//cursor
void toggle_cursor(sfRenderWindow *window, bool status);

//inventory
void manage_inventory(rpg_t *rpg);

#endif
