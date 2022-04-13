/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

sfBool check_collision_npc(rpg_t *rpg)
{
    sfFloatRect player = sfSprite_getGlobalBounds(rpg->spritesheet[rpg->player_stats.skin].sprite);
    sfFloatRect npc = sfSprite_getGlobalBounds(rpg->spritesheet[SP_NPC_SOLDIER].sprite);

    npc.left += 15;
    npc.width += 15;
    npc.height += 15;
    npc.top += 15;
    return (sfFloatRect_intersects(&player, &npc, NULL));
}

void send_chat_bubble(rpg_t *rpg)
{
    rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
}

void quest_soldiers(rpg_t *rpg)
{
    // if (!check_collision_npc(rpg))
    //     return;
    send_chat_bubble(rpg);
}
