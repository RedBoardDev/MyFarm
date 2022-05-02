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
    // printf("buff.fullscreen = %d\n", buff_bool);
    read(fd, &buff_bool, sizeof(bool));
    rpg->params.show_fps = buff_bool;
    // printf("buff.show_fps = %d\n", buff_bool);
    read(fd, &buff_bool, sizeof(bool));
    rpg->params.dark_mode = buff_bool;
    // printf("buff.dark_mode = %d\n", buff_bool);
    read(fd, &buff_int, sizeof(int));
    rpg->params.fps = buff_int;
    // printf("buff.fps = %d\n", buff_int);
    read(fd, &buff_int, sizeof(int));
    rpg->params.index_fps = buff_int;
    // printf("buff.index_fps = %d\n", buff_int);

}

static void read_screens(int fd, rpg_t *rpg)
{
    bool buff_bool = false;
    int buff_int = 0;

    for (int i = 0; i < NBR_SC; ++i) {
        read(fd, &buff_bool, sizeof(bool));
        rpg->screen[i].active = buff_bool;
        // printf("buff_bool[%d] = %d\n", i, buff_bool);
    }
    read(fd, &buff_int, sizeof(int));
    rpg->index_old_s = buff_int;
    // printf("buff_int = %d\n", buff_int);
}

static void read_sounds(int fd, rpg_t *rpg)
{
    float buff = 0;

    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect = buff;
    // printf("volume_effect = %0.2f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect_backup = buff;
    // printf("volume_effect_backup = %0.2f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music = buff;
    // printf("volume_music = %0.2f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music_backup = buff;
    // printf("volume_music_backup = %0.2f\n", buff);
}

static void read_player_stats(int fd, rpg_t *rpg)
{
    sfVector2f buff_vect;
    int buff_int = 0;
    float buff_float = 0;
    bool buff_bool = false;

    read(fd, &buff_vect, sizeof(sfVector2f));
    rpg->player_stats.incr_pos = buff_vect;
    // printf("buff_vect = %0.0f %0.0f\n", buff_vect.x, buff_vect.y);

    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.skin = buff_int;
    // printf("skin = %d\n", buff_int);
    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.money = buff_int;
    // printf("money = %d\n", buff_int);
    read(fd, &buff_float, sizeof(float));
    rpg->player_stats.speed = buff_float;
    // printf("speed = %0.2f\n", buff_float);
    read(fd, &buff_float, sizeof(float));
    rpg->player_stats.life = buff_float;
    // printf("life = %0.2f\n", buff_float);
    read(fd, &buff_int, sizeof(int));
    rpg->player_stats.damage = buff_int;
    // printf("damage = %d\n", buff_int);
    read(fd, &buff_bool, sizeof(bool));
    rpg->player_stats.attack = buff_bool;
    // printf("attack = %d\n", buff_int);

    read(fd, &buff_vect, sizeof(sfVector2f));
    rpg->spritesheet[rpg->player_stats.skin].pos = buff_vect;
    // printf("buff_vect.x = %0.2f %0.2f\n", buff_vect.x, buff_vect.y);

    for (int i = 0; i < 12; ++i) {
        read(fd, &buff_int, sizeof(int));
        rpg->player_stats.inventory.inventory_case[i].item_spritesheet =
        buff_int;
        // printf("buff_int[%d] = %d\n", i, buff_int);
    }
}

void open_file(char *filepath, rpg_t *rpg)
{
    int fd = open(filepath, O_RDONLY);

    if (fd == -1) {
        // printf("non\n");
        return;
    }

    // printf("\nParams -------------\n");
    read_params(fd, rpg);
    // printf("\nScreens -------------\n");
    read_screens(fd, rpg);
    // printf("\nSounds -------------\n");
    read_sounds(fd, rpg);
    // printf("\nStats player -------------\n");
    read_player_stats(fd, rpg);
    toggle_spritesheet_scene(rpg, true, get_current_screen(rpg));
    close(fd);
}
