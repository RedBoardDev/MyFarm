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
    #define FUNCTIONS_BUTTONS {nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, how_play, quest_seller, quest_soldiers, nothing,  \
    skin_blue, skin_brown, skin_cyan, skin_green, skin_grey, skin_pink, \
    skin_red, skin_yellow, nothing, nothing, nothing, launch_game, quit_game, \
    display_custom_skins, back_button, button_next_grotte, nothing, \
    nothing, button_resume_game, button_option_game, button_leave_game, \
    nothing, button_toggle_sound_effect, nothing, nothing, \
    nothing, button_toggle_sound_music, nothing, nothing, button_left_fps,  \
    button_right_fps, nothing,  \
    button_toggle_fullscreen, button_toggle_dark_mode, button_toggle_show_fps, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing, \
    nothing, nothing, nothing, nothing, nothing, nothing, nothing, nothing}
    #define SPAWN_X WIDTH / 2
    #define SPAWN_Y WIDTH / 2 + 80
    // #define SPEED_PLAYER 4
    #define SPEED_PLAYER 1.5
    #define SECOND_TO_MICRO(x) x * 1000000

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
    SP_BACKGROUND_VICRORY_GROTTE,
    SP_MONKEY,
    SP_NPC_SELLER,
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
    SP_BOSS_GOLEM,
    SP_BOSS_GOLEM_PROJ,
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
    SP_ITEM_HOE,
    SP_ITEM_HAMMER,
    SP_ITEM_FISHING_ROD,
    SP_ITEM_SWORD,
    SP_ITEM_CARROT,
    SP_ITEM_PATATO,
    SP_ITEM_TOMATE,
    SP_ITEM_STRAWBERRY,
    SP_ITEM_BEETS,
    SP_MINIMAP,
    SP_MINIMAP_LAYER,
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

enum sounds {
    SOUND_WALK,
    SOUND_DIE_PLAYER,
    SOUND_MENU,
    SOUND_DOOR,
    SOUND_MAIN,
    SOUND_AMBIANT_CAVE,
    NBR_SOUND,
};

enum utilitaire {
    SELECTED_PLAYER = -10,
    CURSOR,
};

enum quests {
    QUEST_SOLDIER,
    QUEST_SELLER,
    NBR_QUEST
};

#endif
