/*
** EPITECH PROJECT, 2021
** myworld
** File description:
** init_all.c
*/

#include "../../include/rpg.h"

static void init_player_boss_stats(player_stats_t *player_stats,
boss_stats_t *boss_stats)
{
    player_stats->incr_pos.x = 0;
    player_stats->incr_pos.y = 0;
    player_stats->money = 110;
    player_stats->attack = false;
    player_stats->speed = 1.0;
    player_stats->life = 20.0;
    player_stats->damage = 1;
    player_stats->drunk = false;
    player_stats->last_damage = sfClock_create();
    boss_stats->damage_executioner = 2;
    boss_stats->damage_golem = 10;
    boss_stats->inc_pos = 0.25;
    boss_stats->life = 20;
    boss_stats->status = ST_IDLE;
    boss_stats->time_next_it = 0;
    boss_stats->movement = sfClock_create();
    boss_stats->rush_to_player = false;
}

static void init_fps(rpg_t *rpg)
{
    rpg->begin.fps.clock = sfClock_create();
    rpg->begin.fps.timer = 0;
    rpg->begin.fps_disp.fps_text = create_text((init_text_t){100, "",
    sfWhite, {WIDTH / 2, HEIGHT / 2}, "assets/fonts/Sriracha-Regular.ttf"});
    rpg->begin.fps_disp.legende = create_text((init_text_t){100, "FPS: ",
    sfWhite, {WIDTH / 2, HEIGHT / 2}, "assets/fonts/Sriracha-Regular.ttf"});
    rpg->begin.fps_disp.clock = sfClock_create();
    rpg->begin.fps_disp.display_clock = sfClock_create();
    rpg->begin.fps_disp.time = 0;
    rpg->begin.fps_disp.fps = 0;
}

static void init_params(rpg_t *rpg)
{
    rpg->params.fullscreen = true;
    rpg->params.show_fps = true;
    rpg->params.dark_mode = true;
    rpg->params.fps = 0;
    rpg->params.index_fps = 0;
    rpg->params.fps_text = create_text((init_text_t){230, "Uncapped",
    sfBlack, {WIDTH / 2 + 403, HEIGHT / 2 - 190},
    "assets/fonts/Sriracha-Regular.ttf"});
}

static void init_icon_window(rpg_t *rpg)
{
    sfImage *img = sfImage_createFromFile("assets/img/logo.png");

    rpg->begin.pixels = sfImage_getPixelsPtr(img);
    sfWindow_setIcon((sfWindow *)rpg->begin.window, 512, 512,
    rpg->begin.pixels);
    sfImage_destroy(img);
}

void init_all(rpg_t *rpg, bool no_sound)
{
    rpg->index_old_s = 0;
    rpg->player_stats.skin = SP_PLAYER;
    init_fps(rpg);
    init_all_events(&rpg->all_events);
    init_imgs(rpg);
    init_screens(rpg);
    rpg->spritesheet = malloc(sizeof(spritesheet_t) * NBR_SP);
    init_spritesheets(rpg->spritesheet);
    init_sounds(rpg, no_sound);
    init_params(rpg);
    init_csfml(&rpg->begin);
    init_view(rpg);
    init_player_boss_stats(&rpg->player_stats, &rpg->boss_stats);
    init_quests(rpg);
    init_inventory(&rpg->player_stats.inventory, rpg);
    init_icon_window(rpg);
    rpg->begin.fps.clock = sfClock_create();
    toggle_cursor(rpg->begin.window, false);
    sfWindow_setFramerateLimit((sfWindow *)rpg->begin.window, rpg->params.fps);
}
