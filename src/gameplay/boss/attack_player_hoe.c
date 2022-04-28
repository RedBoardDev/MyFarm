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

    if (check || rpg->spritesheet[SP_ITEM_HOE].pos.x >=
    rpg->spritesheet[SP_BACKGROUND_GROTTE].pos.x +
    (rpg->spritesheet[SP_BACKGROUND_GROTTE].rect.width / 2)) {
        rpg->player_stats.attack = false;
        rpg->spritesheet[SP_ITEM_HOE].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite,
        rpg->spritesheet[SP_ITEM_HOE].pos);
        rpg->spritesheet[SP_ITEM_HOE].active = false;
        if (check) {
            rpg->boss_stats.life -= 2;
            rpg->boss_stats.life <= 0 ?
            rpg->spritesheet[SP_BOSS_GOLEM].rect.left = 0 : 0;
        }
    }
}

void attack_of_player(rpg_t *rpg)
{
    if (rpg->player_stats.attack)
        player_rush_to_golem(rpg);
    else if (rpg->all_events.enter && !rpg->player_stats.attack) {
        rpg->player_stats.attack = true;
        rpg->spritesheet[SP_ITEM_HOE].pos =
        rpg->spritesheet[rpg->player_stats.skin].pos;
        sfSprite_setPosition(rpg->spritesheet[SP_ITEM_HOE].sprite,
        rpg->spritesheet[SP_ITEM_HOE].pos);
    }
}