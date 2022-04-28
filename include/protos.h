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

void myrpg(int sound);
void die(rpg_t *rpg);
void return_home(rpg_t *rpg);
void manage_menu(rpg_t *rpg);
void teleport_player_scene(rpg_t *rpg, sfImage *image, sfVector2f pos_player);
void execute_all(rpg_t *rpg);

// events
void my_events(rpg_t *rpg);
void events_key_pressed(rpg_t *rpg, sfEvent event);
void events_key_released(sfEvent event, events_t *all_events);
void events_mouse_pressed(rpg_t *rpg, sfEvent event, events_t *all_events);
void events_mouse_released(rpg_t *rpg, sfEvent event, events_t *all_events);
void events_scroll_wheel(sfEvent event, events_t *all_events);
void events_mouse_moved(sfEvent event, events_t *all_events);

//interface
void check_click_buttons(rpg_t *rpg);
void check_mouse_on_all_buttons(rpg_t *rpg);
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
void how_play(rpg_t *rpg);
void back_button(rpg_t *rpg);
void button_next_grotte(rpg_t *rpg);
void menu_pause(rpg_t *rpg);
void buttun_resume_game(rpg_t *rpg);
void buttun_option_game(rpg_t *rpg);
void buttun_option_game_2(rpg_t *rpg);
void buttun_leave_game(rpg_t *rpg);
int check_click_soundbox(rpg_t *rpg);

// init
void init_all(rpg_t *rpg);
void init_imgs(rpg_t *rpg);
void init_main_map(spritesheet_t *spritesheet);
void init_screens(rpg_t *rpg);
void init_sounds(rpg_t *rpg);
void init_menu(spritesheet_t *spritesheet);
void init_spritesheets_rooms(spritesheet_t *spritesheet);
void init_spritesheets(spritesheet_t *spritesheet);
void init_view(rpg_t *rpg);
void init_spritesheet_inventory(spritesheet_t *spritesheet);
void init_all_events(events_t *events);
void init_spritesheets_npc(spritesheet_t *spritesheet);
void init_spritesheets_armed(spritesheet_t *spritesheet);
void init_buttuns_pause_menu(spritesheet_t *spritesheet);
void init_buttuns_option_menu(spritesheet_t *spritesheet);
void init_bosses(spritesheet_t *spritesheet);
void init_spritesheets_food(spritesheet_t *spritesheet);
void init_all_players(spritesheet_t *spritesheet);
void init_spritesheets_quests(spritesheet_t *spritesheet);
void init_quests(rpg_t *rpg);

// utils draw
void my_draw_circle(sfUint8 *framebuffer, sfVector2i center, int radius,
sfColor color);
void my_draw_rectangle(sfUint8 *framebuffer, sfIntRect rect, sfColor color);
void my_draw_line(sfUint8 *framebuffer, sfVector2i point_a, sfVector2i point_b,
sfColor color);
void my_draw_square(sfUint8 *framebuffer, unsigned int size, sfColor color);
void my_putpixel(int x, int y, sfUint8 *framebuffer, sfColor color);
void draw_all(rpg_t *rpg);

// utils
void clean_window(beginning_t *begin, sfColor color);
void init_csfml(beginning_t *beginning);
void destroy_all(rpg_t *rpg);
int my_rand(int min, int max);
bool check_mouse_on_one_button_int(sfVector2i pos, sfFloatRect collision);
bool check_mouse_on_one_button_float(sfVector2f pos, sfFloatRect collision);
void move_life_bar(rpg_t *rpg, int percentage);
void move_life_bar_boss(rpg_t *rpg, int percentage);
sfInt64 get_clock_time(sfClock *clock);
void set_zoom(sfView *view, float new_zoom);
float get_zoom(sfView *view);
int get_size_file(char *path);
int check_status_dialog(quest_t *quest);
int get_chat_into_file(char *filepath, int quest, rpg_t *rpg);
sfColor my_rgb(sfColor color);

// utils sprites
void set_one_sprite(char *filename, spritesheet_t *spritesheet,
init_sprite_t init_sprite);
void draw_one_sprite(beginning_t *begin, sfSprite *sprite, sfIntRect rect,
sfVector2f pos);
void toggle_spritesheet_scene(rpg_t *rpg, bool status, int scene_enum);
void disable_all_screens_gameplay(rpg_t *rpg);

// lib sound
void stop_sound(sfSound *sound);
void play_sound(sfSound *sound, float volume);
void create_sound(char *filepath, bool loop, sound_list_t *sound_list);
void destroy_sound(sfSound *sound, sfSoundBuffer *sound_buffer);
void play_main_sound(rpg_t *rpg);

//view
void set_view(rpg_t *rpg, sfVector2f view_pos);

//move_object
void move_player(rpg_t *rpg);
void move_player_and_view(rpg_t *rpg);
void move_all_fps_independant(rpg_t *rpg);
sfColor get_color_from_player(sfImage *image, sfVector2f pos);
void animate_player(rpg_t *rpg);
void animate_selected_skin(rpg_t *rpg);
void animate_boss_cemetery(rpg_t *rpg);
void animate_boss_grotte(rpg_t *rpg);
void draw_sfImage(sfRenderWindow *window, sfImage *image, sfVector2f pos,
sfIntRect rect);

//cursor
void toggle_cursor(sfRenderWindow *window, bool status);
void set_size_cursor(rpg_t *rpg, float size);

//inventory
void manage_inventory(rpg_t *rpg);
void init_inventory(inventory_t *inventory, rpg_t *rpg);

//quests
void quest_soldiers(rpg_t *rpg);
void disable_quests(rpg_t *rpg, int quests_enum, bool scale);
sfBool check_collision_npc(rpg_t *rpg);
void send_chat_bubble_soldiers(rpg_t *rpg);
void quest_seller(rpg_t *rpg);
void send_chat_bubble_seller(rpg_t *rpg);

// gameplay
sfBool check_collision_executioner(rpg_t *rpg);
sfBool check_collision_golem_proj(rpg_t *rpg);
sfBool check_collision_hoe_to_golem(rpg_t *rpg);
void remove_life_player(rpg_t *rpg, int offset);
void move_player_and_view_vertical(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view);
void move_player_and_view_horizontal(rpg_t *rpg, sfImage *image,
sfVector2f pos_player, bool move_view);

//lib text
sfText *create_text(init_text_t struct_text);
void write_text(sfRenderWindow *window, sfText *text);
void destroy_text(sfText *text, sfFont *font);

// check screens
bool is_in_menu(rpg_t *rpg);
bool is_in_gameplay(rpg_t *rpg);

// animations golem
void animate_idle_golem(rpg_t *rpg);
void animate_die_golem(rpg_t *rpg);
void animate_attack_proj_golem(rpg_t *rpg);

// animations executioner
void animate_attack_1_executioner(rpg_t *rpg);
void animate_attack_2_executioner(rpg_t *rpg);
void animate_idle_executioner(rpg_t *rpg);
void animate_die_executioner(rpg_t *rpg);

// move bosses
void move_proj_golem(rpg_t *rpg);
void move_proj_player(rpg_t *rpg);
void move_executioner(rpg_t *rpg);

//teleport
void teleport_jail(rpg_t *rpg);
void teleport_base(rpg_t *rpg);
void teleport_tente(rpg_t *rpg);
int get_current_screen(rpg_t *rpg);

void stop_all_sounds(rpg_t *rpg);
// fps
void draw_fps(rpg_t *rpg);
int get_fps(rpg_t *rpg);

void move_minimap(rpg_t *rpg);
void attack_of_player(rpg_t *rpg);

#endif
