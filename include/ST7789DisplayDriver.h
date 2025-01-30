#pragma once

#include <Arduino.h>
#include <TFT_eSPI.h>

class ST7789DisplayDriver {
private:
    TFT_eSPI tftDisplay;

public:
    enum class Color : uint16_t {
        BLACK = TFT_BLACK,
        WHITE = TFT_WHITE,
    };

    ST7789DisplayDriver();
    void init();
    void setCursorPosition(int16_t x, int16_t y);
    void setFontSize(uint8_t font);
    void setTextColor(Color textColor);
    void printLine(const String& text);
};
