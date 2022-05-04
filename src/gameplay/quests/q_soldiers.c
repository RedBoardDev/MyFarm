/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** q_soldiers.c
*/

#include "../../../include/rpg.h"

void send_chat_bubble(rpg_t *rpg, char *filepath, int quest_id)
{
    sfVector2f pos_player = rpg->spritesheet[rpg->player_stats.skin].pos;
    sfVector2f pos_dialog = sfText_getPosition(rpg->quest[quest_id].dialog);

    if (rpg->quest[quest_id].active != 1)
        return;
    pos_player.y -= 50;
    pos_player.x -= 20;
    if (rpg->quest[quest_id].speaker == 0) {
        draw_one_sprite(&rpg->begin, rpg->quest[quest_id].bubulle.sprite,
        rpg->quest[quest_id].bubulle.rect,
        rpg->quest[quest_id].bubulle.pos);
        write_text(rpg->begin.window, rpg->quest[quest_id].dialog);
    } else if (rpg->quest[quest_id].speaker == 1) {
        draw_one_sprite(&rpg->begin, rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
        rpg->spritesheet[SP_BUBBLE_CHAT].rect, pos_player);
        pos_player.y -= 20;
        pos_player.x -= 25;
        sfText_setPosition(rpg->quest[quest_id].dialog, pos_player);
        write_text(rpg->begin.window, rpg->quest[quest_id].dialog);
        sfText_setPosition(rpg->quest[quest_id].dialog, pos_dialog);
    }
    if (get_clock_time(rpg->quest[quest_id].clock_chat) >=
    SECOND_TO_MICRO(2)) {
        if (get_chat_into_file(filepath, quest_id, rpg) == 0)
            rpg->quest[quest_id].active = -1;
        sfClock_restart(rpg->quest[quest_id].clock_chat);
    }
}

void quest_soldiers(rpg_t *rpg)
{
    rpg->quest[QUEST_SOLDIER].clock_chat = sfClock_create();
    if (rpg->quest[QUEST_SOLDIER].active != 0) {
        if (rpg->quest[QUEST_SOLDIER].active <= 1
        || check_if_in_inventory(rpg, rpg->quest[QUEST_SOLDIER].active) == -1)
            return;
        else
            remove_item_inventory(rpg, rpg->quest[QUEST_SOLDIER].active);
    }
    rpg->quest[QUEST_SOLDIER].active = 1;
    get_chat_into_file("assets/quest_dialog/soldiers.txt",
    QUEST_SOLDIER, rpg);
}
