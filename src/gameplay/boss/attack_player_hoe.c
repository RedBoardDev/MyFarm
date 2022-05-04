/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** attack_player_hoe.c
*/

#include "../../../include/rpg.h"

static void player_rush_to_golem(rpg_t *rpg)
{
    bool check = check_collision_hoe_to_golem(rpg);
    int hoe = get_item_inv(rpg, I_ATTACK);

    if (check || rpg->spritesheet[hoe].pos.x >=
    rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x +
    (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->player_stats.attack = false;
        rpg->spritesheet[hoe].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[hoe].sprite,
        rpg->spritesheet[hoe].pos);
        rpg->spritesheet[hoe].active = false;
        if (check && hoe == SP_ITEM_PICKAXE) {
            rpg->boss_stats.life -= 2 * (rpg->player_stats.damage) / 10 + 1;
            rpg->boss_stats.life <= 0 ?
            (rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0,
            add_money(rpg, 24), add_item_inventory(rpg, SP_ITEM_PATATO)) : 0;
        }
    }
}

void attack_of_player(rpg_t *rpg)
{
    int hoe = get_item_inv(rpg, I_ATTACK);

    if (rpg->player_stats.attack)
        player_rush_to_golem(rpg);
    else if (rpg->all_events.enter && !rpg->player_stats.attack && hoe != -1) {
        play_sound(rpg->sound.sound_list[SOUND_LAUNCH_WEAPON_PLAYER].sound,
        rpg->sound.volume_effect);
        rpg->player_stats.attack = true;
        rpg->spritesheet[hoe].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[hoe].sprite,
        rpg->spritesheet[hoe].pos);
    }
}
