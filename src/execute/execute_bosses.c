/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** execute_bosses.c
*/

#include "../../include/rpg.h"

void execute_cemetery(rpg_t *rpg)
{
    rpg->spritesheet[SP_LIFE_BAR].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x - 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x - 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOSS].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x + 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX_BOSS].pos =
    (sfVector2f){rpg->screen[SC_CEMETERY].view_pos.x + 320,
    rpg->screen[SC_CEMETERY].view_pos.y - 197};
    move_life_bar(rpg, rpg->player_stats.life * 5);
    move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
    animate_boss_cemetery(rpg);
    if (rpg->player_stats.life <= 0)
        die_player(rpg);
}

void execute_grotte(rpg_t *rpg)
{
    rpg->spritesheet[SP_LIFE_BAR].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x - 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x - 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOSS].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x + 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    rpg->spritesheet[SP_LIFE_BAR_BOX_BOSS].pos =
    (sfVector2f){rpg->screen[SC_GROTTE].view_pos.x + 320,
    rpg->screen[SC_GROTTE].view_pos.y - 197};
    move_life_bar(rpg, rpg->player_stats.life * 5);
    move_life_bar_boss(rpg, rpg->boss_stats.life * 5);
    animate_boss_grotte(rpg);
    if (rpg->player_stats.life <= 0)
        die_player(rpg);
}

static void drink_flask_drunk(rpg_t *rpg)
{
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_DRUNK) {
        sfClock_restart(rpg->player_stats.drunk_time);
        rpg->player_stats.speed += SPEED_DRUNK;
        remove_item_inventory(rpg, SP_FLASK_DRUNK);
        rpg->player_stats.drunk = true;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
}

void drink_flask(rpg_t *rpg)
{
    rpg->all_events.mouse.right = false;
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_ATTACK) {
        remove_item_inventory(rpg, SP_FLASK_ATTACK);
        rpg->player_stats.damage <= 2 ? rpg->player_stats.damage += 1 : 0;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
    if (get_item_inv(rpg, I_ATTACK) == SP_FLASK_SPEED) {
        remove_item_inventory(rpg, SP_FLASK_SPEED);
        rpg->player_stats.speed <= 2 ? rpg->player_stats.speed += 1 : 0;
        play_sound(rpg->sound.sound_list[SOUND_POTION_DRINK].sound,
        rpg->sound.volume_effect);
    }
    drink_flask_drunk(rpg);
}
