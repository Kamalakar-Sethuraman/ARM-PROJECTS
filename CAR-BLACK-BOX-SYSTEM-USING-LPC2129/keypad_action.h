#ifndef KEYPAD_ACTION_H
#define KEYPAD_ACTION_H

typedef enum {
    KEY_NONE = -1,
    KEY_NUM_0 = 0,
    KEY_NUM_1,
    KEY_NUM_2,
    KEY_NUM_3,
    KEY_NUM_4,
    KEY_NUM_5,
    KEY_NUM_6,
    KEY_NUM_7,
    KEY_NUM_8,
    KEY_NUM_9,
    KEY_MENU = 100,
    KEY_BACK,
    KEY_UP,
    KEY_DOWN,
    KEY_ENTER
} key_action_t;

key_action_t Keypad_GetAction(void);

#endif
