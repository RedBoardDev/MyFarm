/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** init_quests.c
*/

#include "../../include/rpg.h"

static void init_skills_inv(rpg_t *rpg)
{
    for (int i = 0; i < NBR_Q; ++i) {
        rpg->quests_inv[i].active = false;
        rpg->quests_inv[i].done = false;
        rpg->quests_inv[i].text = create_text((init_text_t){60,
        rpg->quests_inv[i].text_string, sfBlack, {-1000, -1000},
        "assets/fonts/Sriracha-Regular.ttf"});
    }
    rpg->skills_inv.skill_resistance = create_text((init_text_t){200, "0",
    sfBlack, {-1000, -1000}, "assets/fonts/Sriracha-Regular.ttf"});
    rpg->skills_inv.skill_speed = create_text((init_text_t){200, "0",
    sfBlack, {-1000, -1000}, "assets/fonts/Sriracha-Regular.ttf"});
    rpg->skills_inv.skill_strength = create_text((init_text_t){200, "0",
    sfBlack, {-1000, -1000}, "assets/fonts/Sriracha-Regular.ttf"});
}

static void init_quests_inv(rpg_t *rpg)
{
    rpg->quests_inv = malloc(sizeof(quests_inv_t) * NBR_Q);
    for (int i = 0; i < NBR_Q; ++i)
        rpg->quests_inv[i].text_string = NULL;
    rpg->quests_inv[Q_FIND_INDIAN].text_string = "Find the Indian";
    rpg->quests_inv[Q_TAKE_PEE].text_string = "Bring a jar of pee";
    rpg->quests_inv[Q_BEETROOTS].text_string = "Find some beetroots";
    rpg->quests_inv[Q_FIGHT_EXECUTIONER].text_string = "Fight executioner";
    rpg->quests_inv[Q_TOMATO].text_string = "Find some tomatos";
    rpg->quests_inv[Q_FIGHT_GOLEM].text_string = "Fight the golem";
    rpg->quests_inv[Q_POTATO].text_string = "Find some potatos";
    rpg->quests_inv[Q_FIND_COWS].text_string = "Find the enclose";
    rpg->quests_inv[Q_BUCKET_OF_MILK].text_string = "Find a bucket of milk";
    rpg->quests_inv[Q_REANIMATE_MOM].text_string = "Reanimate your mom!";
    init_skills_inv(rpg);
}

static void init_quests2(rpg_t *rpg)
{
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_SOLDIER].bubulle, (init_sprite_t){{120, 230},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_GUIDE].bubulle, (init_sprite_t){{885, 965},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    set_one_sprite("assets/img/bubble_chat.png",
    &rpg->quest[QUEST_SELLER].bubulle, (init_sprite_t){{1015, 35},
    {0.08, 0.08}, {0, 0, 798, 652}, false, false, false});
    rpg->quest[QUEST_SOLDIER].speaker = -1;
    rpg->quest[QUEST_SELLER].speaker = -1;
    rpg->quest[QUEST_GUIDE].speaker = -1;
    init_quests_inv(rpg);
}

void init_quests(rpg_t *rpg)
{
    rpg->quest = malloc(sizeof(quest_t) * NBR_QUEST);
    rpg->quest[QUEST_SOLDIER].step = 0;
    rpg->quest[QUEST_SOLDIER].active = 0;
    rpg->quest[QUEST_SOLDIER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {92, 210}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_SELLER].step = 0;
    rpg->quest[QUEST_SELLER].active = 0;
    rpg->quest[QUEST_SELLER].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {986, 16}, "assets/fonts/NotoSerif-Regular.ttf"});
    rpg->quest[QUEST_GUIDE].step = 0;
    rpg->quest[QUEST_GUIDE].active = 0;
    rpg->quest[QUEST_GUIDE].dialog =
    create_text((init_text_t){30, "\0", sfBlack,
    {856, 945}, "assets/fonts/NotoSerif-Regular.ttf"});
    init_quests2(rpg);
}
