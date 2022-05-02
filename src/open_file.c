/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** open_file.c
*/

#include "../include/rpg.h"

static void read_params(int fd, rpg_t *rpg)
{
    params_t buff;

    read(fd, &buff, sizeof(params_t));

    rpg->params.fullscreen = buff.fullscreen;
    printf("buff.fullscreen = %d\n", buff.fullscreen);
    rpg->params.show_fps = buff.show_fps;
    printf("buff.show_fps = %d\n", buff.show_fps);
    rpg->params.dark_mode = buff.dark_mode;
    printf("buff.dark_mode = %d\n", buff.dark_mode);
    rpg->params.fps = buff.fps;
    printf("buff.fps = %d\n", buff.fps);
    rpg->params.index_fps = buff.index_fps;
    printf("buff.index_fps = %d\n", buff.index_fps);
}

static void read_screens(int fd, rpg_t *rpg)
{
    bool buff_bool = false;
    int buff_int = 0;

    for (int i = 0; i < NBR_SC; ++i) {
        read(fd, &buff_bool, sizeof(bool));
        rpg->screen[i].active = buff_bool;
        printf("buff_bool[%d] = %d\n", i, buff_bool);
    }
    read(fd, &buff_int, sizeof(int));
    rpg->index_old_s = buff_int;
    printf("buff_int = %d\n", buff_int);
}

static void read_sounds(int fd, rpg_t *rpg)
{
    float buff = 0;

    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect = buff;
    printf("volume_effect = %0.0f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_effect_backup = buff;
    printf("volume_effect_backup = %0.0f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music = buff;
    printf("volume_music = %0.0f\n", buff);
    read(fd, &buff, sizeof(float));
    rpg->sound.volume_music_backup = buff;
    printf("volume_music_backup = %0.0f\n", buff);
}

static void read_player_stats(int fd, rpg_t *rpg)
{
    player_stats_t buff_player_stats;
    sfVector2f buff_vect;
    int buff_int = 0;

    read(fd, &buff_player_stats, sizeof(rpg->player_stats));
    rpg->player_stats.incr_pos = buff_player_stats.incr_pos;
    rpg->player_stats.skin = buff_player_stats.skin;
    printf("buff_player_stats.skin = %d\n", buff_player_stats.skin);
    rpg->player_stats.money = buff_player_stats.money;
    printf("buff_player_stats.money = %d\n", buff_player_stats.money);
    rpg->player_stats.speed = buff_player_stats.speed;
    printf("buff_player_stats.speed = %0.0f\n", buff_player_stats.speed);
    rpg->player_stats.life = buff_player_stats.life;
    printf("buff_player_stats.life = %0.0f\n", buff_player_stats.life);
    rpg->player_stats.damage = buff_player_stats.damage;
    printf("buff_player_stats.damage = %d\n", buff_player_stats.damage);
    rpg->player_stats.attack = buff_player_stats.attack;
    printf("buff_player_stats.attack = %d\n", buff_player_stats.attack);
    read(fd, &buff_vect, sizeof(sfVector2f));
    rpg->spritesheet[rpg->player_stats.skin].pos = buff_vect;
    printf("buff_vect.x = %0.0f %0.0f\n", buff_vect.x, buff_vect.y);

    for (int i = 0; i < 12; ++i) {
        read(fd, &buff_int, sizeof(int));
        rpg->player_stats.inventory.inventory_case[i].item_spritesheet =
        buff_int;
        printf("buff_int[%d] = %d\n", i, buff_int);
    }
}

void open_file(char *filepath, rpg_t *rpg)
{
    int fd = open(filepath, O_RDONLY);

    printf("\nParams -------------\n");
    read_params(fd, rpg);
    printf("\nScreens -------------\n");
    read_screens(fd, rpg);
    printf("\nSounds -------------\n");
    read_sounds(fd, rpg);
    printf("\nStats player -------------\n");
    read_player_stats(fd, rpg);
    close(fd);
}
