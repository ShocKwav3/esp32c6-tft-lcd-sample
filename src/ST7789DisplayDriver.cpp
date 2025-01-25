#include "ST7789DisplayDriver.h"

const uint16_t ST7789DisplayDriver::COLOR_BLACK = TFT_BLACK;
const uint16_t ST7789DisplayDriver::COLOR_WHITE = TFT_WHITE;

ST7789DisplayDriver::ST7789DisplayDriver() : tftDisplay(TFT_eSPI()) {}

void ST7789DisplayDriver::init() {
    tftDisplay.init();
    tftDisplay.setRotation(1); // Adjust orientation (1: Landscape, 0: Portrait, etc.)
    tftDisplay.fillScreen(ST7789DisplayDriver::COLOR_BLACK);
}

void ST7789DisplayDriver::setCursorPosition(int16_t x, int16_t y) {
    tftDisplay.setCursor(x, y);
}

void ST7789DisplayDriver::setFontSize(uint8_t fontSize) {
    tftDisplay.setTextFont(fontSize);
}

void ST7789DisplayDriver::setTextColor(uint16_t textColor) {
    tftDisplay.setTextColor(textColor);
}

void ST7789DisplayDriver::printLine(const String& text) {
    tftDisplay.println(text);
}
