/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** save_progress.c
*/

#include "../../include/rpg.h"

static void save_params(int fd, rpg_t *rpg)
{
    write(fd, &rpg->params.fullscreen, sizeof(bool));
    write(fd, &rpg->params.show_fps, sizeof(bool));
    write(fd, &rpg->params.dark_mode, sizeof(bool));
    write(fd, &rpg->params.fps, sizeof(int));
    write(fd, &rpg->params.index_fps, sizeof(int));
}

static void save_screens_and_sounds(int fd, rpg_t *rpg)
{
    for (int i = 0; i < NBR_SC; ++i)
        write(fd, &rpg->screen[i].active, sizeof(bool));
    write(fd, &rpg->index_old_s, sizeof(int));
    write(fd, &rpg->sound.volume_effect, sizeof(float));
    write(fd, &rpg->sound.volume_effect_backup, sizeof(float));
    write(fd, &rpg->sound.volume_music, sizeof(float));
    write(fd, &rpg->sound.volume_music_backup, sizeof(float));
}

static void save_player_stats(int fd, rpg_t *rpg)
{
    write(fd, &rpg->player_stats.incr_pos, sizeof(sfVector2f));
    write(fd, &rpg->player_stats.skin, sizeof(int));
    write(fd, &rpg->player_stats.money, sizeof(int));
    write(fd, &rpg->player_stats.speed, sizeof(float));
    write(fd, &rpg->player_stats.life, sizeof(float));
    write(fd, &rpg->player_stats.damage, sizeof(int));
    write(fd, &rpg->player_stats.attack, sizeof(bool));
    write(fd, &rpg->spritesheet[rpg->player_stats.skin].pos,
    sizeof(sfVector2f));
    for (int i = 0; i < 12; ++i)
        write(fd, &rpg->player_stats.inventory.inventory_case[i].
        item_spritesheet, sizeof(int));
}

static void save_boss_stats(int fd, rpg_t *rpg)
{
    write(fd, &rpg->boss_stats.life, sizeof(float));
    write(fd, &rpg->boss_stats.damage_executioner, sizeof(int));
    write(fd, &rpg->boss_stats.damage_golem, sizeof(int));
    write(fd, &rpg->boss_stats.inc_pos, sizeof(float));
    write(fd, &rpg->boss_stats.status, sizeof(int));
    write(fd, &rpg->boss_stats.time_next_it, sizeof(float));
    write(fd, &rpg->boss_stats.rush_to_player, sizeof(bool));
}

void save_file(char *filepath, rpg_t *rpg)
{
    int fd = open(filepath, O_WRONLY | O_CREAT, 0664);

    save_params(fd, rpg);
    save_screens_and_sounds(fd, rpg);
    save_player_stats(fd, rpg);
    save_boss_stats(fd, rpg);
    close(fd);
}
