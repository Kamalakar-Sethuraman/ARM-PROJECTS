#include "lcd.h"
#include "ui.h"
#include "keypad_action.h"

int main(void)
{
    key_action_t key;

    LCD_INIT();
    UI_Init();

    while(1)
    {
        key = Keypad_GetAction();
        if(key != KEY_NONE)
        {
            UI_HandleKey(key);
        }

        UI_UpdateDashboard();   // speed + gear refresh
    }
}
