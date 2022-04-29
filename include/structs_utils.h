/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** structs_utils.c
*/

#ifndef STRUCT_UTILS
    #define STRUCT_UTILS

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
    bool change_sprite_on_mouse;
} init_sprite_t;

typedef struct {
    int size;
    char *str;
    sfColor color;
    sfVector2f pos;
    char *filepath_font;
} init_text_t;

#endif
