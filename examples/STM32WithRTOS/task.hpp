#include "STM32FreeRTOS.h"//STM32duino FreeRTOS
#include "LiquidCrystal_I2C.h"
// tasks

void taskLiquidCrystalI2C(void *parameter);

// task create
void taskCreate();
void taskCreate()
{
    xTaskCreate(taskLiquidCrystalI2C,
                "LiquidCrystalI2C",
                configMINIMAL_STACK_SIZE + 256,
                NULL,
                3,
                NULL);
}

void taskLiquidCrystalI2C(void *parameter)
{
    LiquidCrystal_I2C lcd(0x27, 16, 2);                
    // the first parameter is SDA, the second is SCL                        
    // LiquidCrystal_I2C lcd2(PB11, PB10, 0x27, 16, 2);

    lcd.init();
    lcd.backlight();
    // lcd2.init();
    // lcd2.backlight();
    for (;;)
    {
        lcd.setCursor(0, 0);
        lcd.print("1:Hello,World!");
        lcd.setCursor(0, 1);
        lcd.print("Modified by LYF!");

        // lcd2.setCursor(0, 0);
        // lcd2.print("2:Hello,World!");
        // lcd2.setCursor(0, 1);
        // lcd2.print("Modified by LYF!");
        vTaskDelay(2000 / portTICK_PERIOD_MS);
        lcd.clear();
        // lcd2.clear();
        vTaskDelay(1000 / portTICK_PERIOD_MS);
    }
}
