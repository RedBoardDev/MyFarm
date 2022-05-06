/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** quetes_inv.c
*/

#include "../../../include/rpg.h"

static void draw_skills_inventory(rpg_t *rpg)
{
    sfVector2f pos = {rpg->spritesheet[SP_INVENTORY].pos.x + 280,
    rpg->spritesheet[SP_INVENTORY].pos.y - 26};

    sfText_setPosition(rpg->skills_inv.skill_speed, pos);
    sfText_setString(rpg->skills_inv.skill_speed,
    my_itoa(rpg->player_stats.speed));
    pos.y += 46;
    sfText_setPosition(rpg->skills_inv.skill_resistance, pos);
    sfText_setString(rpg->skills_inv.skill_resistance,
    my_itoa(rpg->player_stats.resistance));
    pos.y += 46;
    sfText_setPosition(rpg->skills_inv.skill_strength, pos);
    sfText_setString(rpg->skills_inv.skill_strength,
    my_itoa(rpg->player_stats.damage));
    write_text(rpg->begin.window, rpg->skills_inv.skill_resistance);
    write_text(rpg->begin.window, rpg->skills_inv.skill_speed);
    write_text(rpg->begin.window, rpg->skills_inv.skill_strength);
}

void draw_quests_inventory(rpg_t *rpg)
{
    sfVector2f pos = {rpg->spritesheet[SP_INVENTORY].pos.x - 350,
    rpg->spritesheet[SP_INVENTORY].pos.y - 25};

    for (int i = 0; i < NBR_Q; ++i) {
        if (rpg->quests_inv[i].active) {
            sfText_setPosition(rpg->quests_inv[i].text, pos);
            sfText_setStyle(rpg->quests_inv[i].text, (rpg->quests_inv[i].done ?
            sfTextStrikeThrough : sfTextRegular));
            write_text(rpg->begin.window, rpg->quests_inv[i].text);
            pos.y += 14;
        }
    }
    draw_skills_inventory(rpg);
}

void add_quest_inv(rpg_t *rpg, int enum_q)
{
    rpg->quests_inv[enum_q].active = true;
    send_notif(rpg, rpg->quests_inv[enum_q].text_string);
}

void mark_quest_done(rpg_t *rpg, int enum_q)
{
    rpg->quests_inv[enum_q].done = true;
    send_notif(rpg, "Quest done! GG");
}

int check_status_dialog(quest_t *quest)
{
    for (int i = 0; i < NBR_QUEST; ++i)
        if (quest[i].active == 1)
            return (1);
    return (0);
}
