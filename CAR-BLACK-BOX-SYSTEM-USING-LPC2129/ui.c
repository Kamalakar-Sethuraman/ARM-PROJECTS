#include "ui.h"
#include "lcd.h"
#include "adc.h"
#include "uart.h"
#include "eeprom.h"

static screen_t screen = SCREEN_DASHBOARD;
static unsigned char pass[4];
static unsigned char idx = 0;
static const unsigned char stored_pass[4] = {1,2,3,4};

void UI_ShowDashboard(void)
{
    LCD_CMD(0x01);
    LCD_STRING("Speed:");
    LCD_CMD(0xC0);
    LCD_STRING("Gear:");
}

void UI_ShowMenu(void)
{
    LCD_CMD(0x01);
    LCD_STRING("1.View Logs");
    LCD_CMD(0xC0);
    LCD_STRING("2.Back");
}

void UI_ShowLogin(void)
{
    LCD_CMD(0x01);
    LCD_STRING("Enter Password");
    LCD_CMD(0xC0);
    idx = 0;
}

void UI_ShowLogs(void)
{
    LCD_CMD(0x01);
    LCD_STRING("Downloading");
    UART_SendLogs();
}

void UI_Init(void)
{
    ADC_Init();
    UART_Init();
    EEPROM_Init();
    UI_ShowDashboard();
}

void UI_UpdateDashboard(void)
{
    if(screen != SCREEN_DASHBOARD) return;

    int speed = ADC_ReadSpeed();   // simulated
    int gear  = ADC_ReadGear();    // simulated

    LCD_CMD(0x87);
    LCD_INTEGER(speed);

    LCD_CMD(0xC7);
    LCD_INTEGER(gear);
}

void UI_HandleKey(key_action_t key)
{
    switch(screen)
    {
        case SCREEN_DASHBOARD:
            if(key == KEY_MENU)
            {
                screen = SCREEN_MENU;
                UI_ShowMenu();
            }
            break;

        case SCREEN_MENU:
            if(key == KEY_NUM_1)
            {
                screen = SCREEN_LOGIN;
                UI_ShowLogin();
            }
            else if(key == KEY_BACK)
            {
                screen = SCREEN_DASHBOARD;
                UI_ShowDashboard();
            }
            break;

        case SCREEN_LOGIN:
            if(key <= 9)
            {
                pass[idx++] = key;
                LCD_STRING("*");
                if(idx == 4)
                {
                    if(!memcmp(pass, stored_pass, 4))
                    {
                        screen = SCREEN_VIEW_LOGS;
                        UI_ShowLogs();
                    }
                    else
                    {
                        screen = SCREEN_DASHBOARD;
                        UI_ShowDashboard();
                    }
                }
            }
            break;

        case SCREEN_VIEW_LOGS:
            if(key == KEY_BACK)
            {
                screen = SCREEN_MENU;
                UI_ShowMenu();
            }
            break;
    }
}
