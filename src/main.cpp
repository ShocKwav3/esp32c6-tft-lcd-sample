#include <ST7789DisplayDriver.h>

ST7789DisplayDriver display;

void setup()
{
    display.init();
    display.setCursorPosition(15, 0);
    display.setFontSize(4);
    display.setTextColor(ST7789DisplayDriver::COLOR_WHITE);
    display.printLine("Hello");
    display.printLine("World");
    display.printLine("SUP?");
}

void loop()
{

}