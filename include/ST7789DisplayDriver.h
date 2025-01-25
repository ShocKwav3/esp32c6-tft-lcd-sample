#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

class ST7789DisplayDriver {
private:
    TFT_eSPI tftDisplay;

public:
    static const uint16_t COLOR_BLACK;
    static const uint16_t COLOR_WHITE;

    ST7789DisplayDriver();
    void init();
    void setCursorPosition(int16_t x, int16_t y);
    void setFontSize(uint8_t font);
    void setTextColor(uint16_t color);
    void printLine(const String& text);
};
