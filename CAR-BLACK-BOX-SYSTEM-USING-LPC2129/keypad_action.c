#include "keypad_action.h"
#include "keypad.h"

key_action_t Keypad_GetAction(void)
{
    unsigned int k = keyscan();

    switch(k)
    {
        case 1:  return KEY_MENU;
        case 2:  return KEY_BACK;
        case 3:  return KEY_UP;
        case 4:  return KEY_DOWN;
        case 5:  return KEY_ENTER;

        case 6:  return KEY_NUM_0;
        case 7:  return KEY_NUM_1;
        case 8:  return KEY_NUM_2;
        case 9:  return KEY_NUM_3;
        case 10: return KEY_NUM_4;
        case 11: return KEY_NUM_5;
        case 12: return KEY_NUM_6;
        case 13: return KEY_NUM_7;
        case 14: return KEY_NUM_8;
        case 15: return KEY_NUM_9;

        default: return KEY_NONE;
    }
}
