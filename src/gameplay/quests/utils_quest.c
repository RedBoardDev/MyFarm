/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** utils_quest.c
*/

#include "../../../include/rpg.h"

static int draw_bubulle_npc(rpg_t *rpg, sfSprite *sprite,
sfIntRect rect, sfVector2f pos)
{
    if (rpg->screen[SC_INVENTORY].active)
        return (0);
    draw_one_sprite(&rpg->begin, sprite, rect, pos);
    return (1);
}

static void set_pos_player(rpg_t *rpg, int quest_id,
sfVector2f pos_player, sfVector2f pos_dialog)
{
    int put_txt = 0;

    if (rpg->quest[quest_id].speaker == 0) {
        put_txt = draw_bubulle_npc(rpg, rpg->quest[quest_id].bubulle.sprite,
        rpg->quest[quest_id].bubulle.rect, rpg->quest[quest_id].bubulle.pos);
        if (put_txt)
            write_text(rpg->begin.window, rpg->quest[quest_id].dialog);
    } else if (rpg->quest[quest_id].speaker == 1) {
        put_txt = draw_bubulle_npc(rpg, rpg->spritesheet[SP_BUBBLE_CHAT].sprite,
        rpg->spritesheet[SP_BUBBLE_CHAT].rect, pos_player);
        pos_player.y -= 20;
        pos_player.x -= 25;
        sfText_setPosition(rpg->quest[quest_id].dialog, pos_player);
        put_txt ? write_text(rpg->begin.window, rpg->quest[quest_id].dialog)
        : 0;
        sfText_setPosition(rpg->quest[quest_id].dialog, pos_dialog);
    }
}

void send_chat_bubble(rpg_t *rpg, char *filepath, int quest_id)
{
    sfVector2f pos_player = rpg->spritesheet[rpg->player_stats.skin].pos;
    sfVector2f pos_dialog = sfText_getPosition(rpg->quest[quest_id].dialog);

    if (rpg->quest[quest_id].active != 1)
        return;
    pos_player.y -= 50;
    pos_player.x -= 20;
    set_pos_player(rpg, quest_id, pos_player, pos_dialog);
    if (rpg->all_events.enter) {
        rpg->all_events.enter = false;
        if (get_chat_into_file(filepath, quest_id, rpg) == 0)
            rpg->quest[quest_id].active = -1;
    }
}

static int check_quest_status_step(rpg_t *rpg, int i_quest)
{
    if (rpg->quest[i_quest].active <= 1)
        return (1);
    if (rpg->quest[i_quest].speaker == -2
    && check_if_in_inventory(rpg, rpg->quest[i_quest].active) != -1) {
        remove_item_inventory(rpg, rpg->quest[i_quest].active);
        return (0);
    }
    if (rpg->quest[i_quest].speaker == -3
    && rpg->quest[i_quest].active >= NBR_SP
    && rpg->quest[rpg->quest[i_quest].active - NBR_SP].active == -1)
        return (0);
    return (1);
}

void quest_launch(rpg_t *rpg, int i_quest, char *filepath)
{
    if (rpg->quest[i_quest].active != 0) {
        if (check_quest_status_step(rpg, i_quest))
            return;
    }
    rpg->quest[i_quest].active = 1;
    get_chat_into_file(filepath, i_quest, rpg);
}
