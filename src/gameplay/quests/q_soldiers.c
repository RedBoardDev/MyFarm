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

void send_chat_bubble_soldiers(sfRenderWindow *window, rpg_t *rpg)
{
    if (rpg->quest[QUEST_SOLDIER].step == -1
    || rpg->quest[QUEST_SOLDIER].step == 0)
        return;
    switch (rpg->quest[QUEST_SOLDIER].step) {
    case 1:
        write_text(window, rpg->quest[QUEST_SOLDIER].npc, "Bien le bonjour !\n Que veux tu ?");
        break;
    case 2:
        write_text(window, rpg->quest[QUEST_SOLDIER].player, "Moi vouloir épée");
        break;
    case 3:
        write_text(window, rpg->quest[QUEST_SOLDIER].npc,
        "Si toi vouloir, moi vouloir\npoisson. Va donc voler\nla canne a peche\na la prison pour pecher.");
        break;
    default:
        break;
    }
    if (get_clock_time(rpg->quest[QUEST_SOLDIER].clock_chat) >= 10000000) {
        ++rpg->quest[QUEST_SOLDIER].step;
        // printf("RRR\n");
        sfClock_restart(rpg->quest[QUEST_SOLDIER].clock_chat);
    }
}

void quest_soldiers(rpg_t *rpg)
{
    rpg->quest[QUEST_SOLDIER].clock_chat = sfClock_create();
    rpg->spritesheet[SP_BUBBLE_CHAT].active = true;
    if (rpg->quest[QUEST_SOLDIER].step == 0)
        rpg->quest[QUEST_SOLDIER].step = 1;
}
