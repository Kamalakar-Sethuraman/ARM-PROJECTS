#ifndef UI_H
#define UI_H

#include "keypad_action.h"

typedef enum {
    SCREEN_DASHBOARD,
    SCREEN_MENU,
    SCREEN_LOGIN,
    SCREEN_VIEW_LOGS
} screen_t;

void UI_Init(void);
void UI_HandleKey(key_action_t key);
void UI_UpdateDashboard(void);

#endif
