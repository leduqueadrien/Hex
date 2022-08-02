
#pragma once

typedef enum MESSAGE {
    NONE,                // 0
    ASK_FOR_NUM_TURN,    // 1
    SEND_NUM_TURN,       // 2
    ASK_FOR_PLAYER_TURN, // 3
    SEND_PLAYER_TURN,    // 4
    ASK_FOR_LAST_MOVE,   // 5
    SEND_LAST_MOVE,      // 6
    ASK_FOR_MOVE,        // 7
    SEND_MOVE,           // 8
    ASK_FOR_GAME_INIT,   // 9
    DONE_GAME_INIT,      // 10
    END_GAME,            // 11
    ACK_END_GAME,        // 12
    ASK_NEXT_TURN,       // 13
    DONE_NEXT_TURN,      // 14
    TURN_MAKE,           // 15
    END_DISPLAY          // 16
} MESSAGE;
