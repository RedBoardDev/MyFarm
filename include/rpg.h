/*
** EPITECH PROJECT, 2021
** myrpg
** File description:
** myrpg.h
*/

#ifndef MY_RPG_H
    #define MY_RPG_H

    #include "my.h"
    #include "protos.h"
    #include "struct.h"
    #define RADIAN(x) x * 3.14159265359 / 180
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, how_play, quest_soldiers, nothing, skin_blue, \
    skin_brown, skin_cyan, skin_green, skin_grey, skin_pink, skin_red, \
    skin_yellow, nothing, nothing, nothing, nothing, launch_game, quit_game, \
    display_custom_skins, back_button, button_next_grotte, nothing, \
    nothing, buttun_resume_game, buttun_option_game, buttun_leave_game, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing}
    #define SCREENS_INT extern int screen_menu[];   \
                        extern int screen_custom[];   \
                        extern int screen_game[];   \
                        extern int screen_base[]; \
                        extern int screen_jail[]; \
                        extern int screen_grotte[]; \
                        extern int screen_inventory[]; \
                        extern int screen_how_play[]; \
                        extern int screen_victory_grotte[]; \
                        extern int screen_pause_menu[];
    #define SPAWN_X WIDTH / 2
    #define SPAWN_Y WIDTH / 2 + 80
    #define SPEED_PLAYER 1.5
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
    SP_BACKGROUND_HOW_PLAY,
    SP_BACKGROUND_VICRORY_GROTTE,
    SP_MONKEY,
    SP_NPC_SOLDIER,
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
    SP_SOUND_CLICK,
    SP_SOUND_POTENTIO,
    SP_SOUND_SELECT,
    SP_PLAY,
    SP_QUIT,
    SP_CUSTOM,
    SP_BACK,
    SP_NEXT_GROTTE,
    SP_BUBBLE_CHAT,
    SP_INVENTORY,
    SP_RESUME,
    SP_OPTION,
    SP_LEAVE_GAME,
    SP_LIFE_BAR_BOX,
    SP_LIFE_BAR,
    SP_LIFE_BAR_BOX_BOSS,
    SP_LIFE_BAR_BOSS,
    SP_ITEM_SHOVEL,
    SP_ITEM_HOE,
    SP_ITEM_HAMMER,
    SP_ITEM_FISHING_ROD,
    SP_ITEM_SWORD,
    SP_ITEM_CARROT,
    SP_ITEM_PATATO,
    SP_ITEM_TOMATE,
    SP_ITEM_STRAWBERRY,
    SP_ITEM_BEETS,
    SP_CURSOR,
    NBR_SP
};

enum status_boss {
    ST_IDLE,
    ST_ATTACK_1,
    ST_ATTACK_2,
    ST_DIE,
    NBR_ST
};

enum screens {
    SC_MENU,
    SC_CUSTOM_SKINS,
    SC_HOW_PLAY,
    SC_MAIN_MAP,
    SC_BASE,
    SC_GROTTE,
    SC_INVENTORY,
    SC_PAUSE,
    NBR_SC
};

enum bleu_maisons {
    B_BASE = 100,
    B_JAIL,
    B_TENTE,
    B_GROTTE,
    B_TAVERNE,
    NBR_B
};

enum sounds {
    SOUND_MENU,
    SOUND_WALK,
    SOUND_DOOR,
    NBR_SOUND,
};

enum utilitaire {
    SELECTED_PLAYER = -10,
    CURSOR,
};

enum quests {
    QUEST_SOLDIER,
    NBR_QUEST
};

#endif
