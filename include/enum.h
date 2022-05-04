/*
** EPITECH PROJECT, 2021
** my_rpg
** File description:
** enum.c
*/

#ifndef ENUM_H
    #define ENUM_H

enum size_window {
    WIDTH = 1920,
    HEIGHT = 1080
};

enum sprites {
    SP_BACKGROUND_SC_MAIN_MAP,
    SP_BACKGROUND_SC_MENU,
    SP_BACKGROUND_SC_BASE,
    SP_BACKGROUND_JAIL,
    SP_BACKGROUND_GROTTE,
    SP_BACKGROUND_CEMETERY,
    SP_BACKGROUND_TENTE,
    SP_BACKGROUND_TAVERNE,
    SP_BACKGROUND_HOW_PLAY,
    SP_BACKGROUND_VICTORY_GROTTE,
    SP_BED_SLEEP,
    SP_MAPS_TAVERNE,
    SP_GUI_SHOP,
    SP_SHOP_BUTTON1,
    SP_SHOP_BUTTON2,
    SP_SHOP_BUTTON3,
    SP_SHOP_BUTTON4,
    SP_MONKEY,
    SP_NPC_SELLER,
    SP_NPC_SOLDIER,
    SP_NPC_GUIDE,
    SP_PLAYER,
    SP_PLAYER_BLUE,
    SP_PLAYER_BROWN,
    SP_PLAYER_CYAN,
    SP_PLAYER_GREEN,
    SP_PLAYER_GREY,
    SP_PLAYER_PINK,
    SP_PLAYER_RED,
    SP_PLAYER_YELLOW,
    SP_BOSS_EXECUTIONER,
    SP_BOSS_GOLEM,
    SP_BOSS_GOLEM_PROJ,
    SP_PLAY,
    SP_QUIT,
    SP_CUSTOM,
    SP_OPTIONS_MAIN_MENU,
    SP_BACK,
    SP_NEXT_GROTTE,
    SP_BUBBLE_CHAT,
    SP_INVENTORY,
    SP_BOX_BUTTON_EFFECT,
    SP_SOUND_EFFECT,
    SP_SOUNDBAR_EFFECT,
    SP_SOUND_SLIDER_EFFECT,
    SP_BOX_BUTTON_MUSIC,
    SP_SOUND_MUSIC,
    SP_SOUNDBAR_MUSIC,
    SP_SOUND_SLIDER_MUSIC,
    SP_ARROW_LEFT,
    SP_ARROW_RIGHT,
    SP_FPS_SELECTOR,
    SP_BUTTON_SCREEN,
    SP_BUTTON_ON_OFF_LUM,
    SP_BUTTON_ON_OFF_FPS,
    SP_LIFE_BAR_BOX,
    SP_LIFE_BAR,
    SP_LIFE_BAR_BOX_BOSS,
    SP_LIFE_BAR_BOSS,
    SP_ITEM_SHOVEL,
    SP_ITEM_PRISONER_PEE,
    SP_ITEM_HOE,
    SP_ITEM_PICKAXE,
    SP_ITEM_FISHING_ROD,
    SP_ITEM_SWORD,
    SP_ITEM_CARROT,
    SP_ITEM_PATATO,
    SP_ITEM_TOMATE,
    SP_ITEM_STRAWBERRY,
    SP_ITEM_BEETS,
    SP_ITEM_ARMOR,
    SP_FLASK_SPEED,
    SP_FLASK_ATTACK,
    SP_FLASK_DRUNK,
    SP_MINIMAP_TAVERNE,
    SP_MINIMAP,
    SP_MINIMAP_LAYER,
    SP_NOTIF,
    SP_RESUME,
    SP_OPTION,
    SP_LEAVE_GAME,
    SP_CURSOR,
    NBR_SP
};

enum screens {
    SC_MAIN_MAP,
    SC_MENU,
    SC_CUSTOM_SKINS,
    SC_HOW_PLAY,
    SC_BASE,
    SC_VICTORY_CEMETERY,
    SC_CEMETERY,
    SC_VICTORY_GROTTE,
    SC_GROTTE,
    SC_TAVERNE,
    SC_JAIL,
    SC_TENTE,
    SC_OPTION,
    SC_INVENTORY,
    SC_PAUSE,
    NBR_SC
};

enum status_boss {
    ST_IDLE,
    ST_ATTACK_1,
    ST_ATTACK_2,
    ST_DIE,
    NBR_ST
};

enum bleu_maisons {
    B_BASE = 100,
    B_JAIL,
    B_TENTE,
    B_GROTTE,
    B_TAVERNE,
    B_CEMETERY,
    NBR_B
};

enum cases_inv {
    I_ATTACK,
    I_ARMOR,
    I_CASE_1,
    I_CASE_2,
    I_CASE_3,
    I_CASE_4,
    I_CASE_5,
    I_CASE_6,
    I_CASE_7,
    I_CASE_8,
    I_CASE_9,
    I_CASE_MOVE
};

enum sounds {
    SOUND_LAUNCH_WEAPON_PLAYER,
    SOUND_DEATH_GOLEM,
    SOUND_WALK,
    SOUND_WATER,
    SOUND_POTION_DRINK,
    SOUND_LOST_FOCUS,
    SOUND_DIE_PLAYER,
    SOUND_MENU,
    SOUND_DOOR,
    SOUND_MAIN,
    SOUND_GRAVEYARD,
    SOUND_AMBIANT_CAVE,
    SOUND_NIGHT,
    NBR_SOUND,
};

enum utilitaire {
    SELECTED_PLAYER = -10,
    CURSOR,
    INFIN = 2147483647
};

enum quests {
    QUEST_SOLDIER,
    QUEST_SELLER,
    QUEST_GUIDE,
    NBR_QUEST
};

#endif
