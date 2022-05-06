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

static void save_quests_pnj_dialogs(int fd, rpg_t *rpg)
{
    for (int i = 0; i < NBR_QUEST; ++i) {
        write(fd, &rpg->quest[i].active, sizeof(int));
        write(fd, &rpg->quest[i].step, sizeof(int));
        write(fd, &rpg->quest[i].speaker, sizeof(int));
    }
}

void save_file(char *filepath, rpg_t *rpg)
{
    int fd = open(filepath, O_WRONLY | O_CREAT, 0664);

    save_params(fd, rpg);
    save_screens_and_sounds(fd, rpg);
    save_player_stats(fd, rpg);
    save_boss_stats(fd, rpg);
    save_quests_pnj_dialogs(fd, rpg);
    close(fd);
}
