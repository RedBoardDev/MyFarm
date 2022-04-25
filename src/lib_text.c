/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** lib_text.c
*/

#include "../include/rpg.h"

sfText *create_text(init_text_t struct_text)
{
    sfText *text = sfText_create();
    sfFont *font = sfFont_createFromFile(struct_text.filepath_font);

    sfText_setString(text, struct_text.str);
    sfText_setFont(text, font);
    sfText_setCharacterSize(text, struct_text.size);
    sfText_setPosition(text, struct_text.pos);
    sfText_setColor(text, struct_text.color);
    sfText_scale(text, (sfVector2f){0.2, 0.2});
    return (text);
}

void write_text(sfRenderWindow *window, sfText *text)
{
    sfRenderWindow_drawText(window, text, NULL);
}

void destroy_text(sfText *text, sfFont *font)
{
    sfText_destroy(text);
    sfFont_destroy(font);
}
