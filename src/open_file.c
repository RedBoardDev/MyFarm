/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** open_file.c
*/

#include "../include/rpg.h"

static void read_params(int fd, rpg_t *rpg)
{
    bool buff_bool = false;
    int buff_int = 0;

    read(fd, &buff_bool, sizeof(bool));
    rpg->params.fullscreen = buff_bool;
    read(fd, &buff_bool, sizeof(bool));
    rpg->params.show_fps = buff_bool;
    read(fd, &buff_bool, sizeof(bool));
    rpg->params.dark_mode = buff_bool;
    read(fd, &buff_int, sizeof(int));
    rpg->params.fps = buff_int;
    read(fd, &buff_int, sizeof(int));
    rpg->params.index_fps = buff_int;

}

static void read_screens(int fd, rpg_t *rpg)
{
    bool buff_bool = false;
    int buff_int = 0;

    for (int i = 0; i < NBR_SC; ++i) {
        read(fd, &buff_bool, sizeof(bool));
        rpg->screen[i].active = buff_bool;
    }
    read(fd, &buff_int, sizeof(int));
    rpg->index_old_s = buff_int;
}

static void read_sounds(int fd, rpg_t *rpg)
{
    float buff = 0;

    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect = buff;
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect_backup = buff;
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music = buff;
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music_backup = buff;
}

void open_file(char *filepath, rpg_t *rpg)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1)
        return;
    read_params(fd, rpg);
    read_screens(fd, rpg);
    read_sounds(fd, rpg);
    read_player_stats(fd, rpg);
    toggle_spritesheet_scene(rpg, true, get_current_screen(rpg));
    close(fd);
}
