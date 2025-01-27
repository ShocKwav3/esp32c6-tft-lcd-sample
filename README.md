# ESP32C6 LCD Sample

This project demonstrates how to use an ESP32C6 microcontroller to interface with a LCD display. The project is developed using PlatformIO and Arduino. The simulator used is Wokwi.

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Hardware Requirements](#hardware-requirements)
- [Software Requirements](#software-requirements)
- [Installation](#installation)
- [Usage](#usage)

## Introduction
This project aims to provide a simple and effective way to control a LCD display using an ESP32C6 microcontroller. It includes sample code and instructions to get started quickly. I used a Waveshare ESP32C6 board with integreated 1.47inch display.

## Features
- Interface with LCD display
- Display text and graphics
- Easy-to-use API
- Simulator setup (Wokwi)

## Hardware Requirements
- ESP32C6 microcontroller
- LCD display

## Software Requirements
- PlatformIO IDE
- Arduino core 3.0.x for ESP32C6
- Wokwi/Wokwi for vscode (Optional)
- Libraries
    - `tft_eSPI`

## Installation
1. Clone the repository
2. Open the project in PlatformIO IDE
3. Install the required libraries

## Usage
1. **Connect the hardware:**
    - Connect the ESP32C6 to the LCD display via SPI according to pinout diagram.
        - For testing with simulator it's not necessary
2. **Update config:**
    - Open `config/device/tft_config.h` and make changes according to connection made previous step.
        - `config/device/tft_config.h` in the case of simulator
3. **Compile:**
    - Select env.
        - Select between `device` and `sim` env from the switcher in vscode status bar
    - Build using PlatformIO
4. **Upload the code:**
    - Upload the code to the ESP32C6 using PlatformIO.
    - No action required for simulator.
5. **Run the project:**
    - Power on the board and the LCD and test should show up on the display.
    - For simulator, click on diagram.json in vscode. Press play.

## Project specific quarks
- Arduino core 3.0.x for ESP32C6
    - Arduino is officially not available through platformio. I used a community branch which allows developent for such case. Check `platform` in `platformio.ini`.
- `tft_eSPI` Library setup
    - Due to the lack of support of ESP32C6, at this time, I used [Cincinnatu](https://github.com/Cincinnatu)'s branch which has a [PR](https://github.com/Bodmer/TFT_eSPI/pull/3399) to the library, based on [this issue](https://github.com/Bodmer/TFT_eSPI/issues/3255), but not yet merged.
    - Using it with the same name but pointed to the branch by specifying the url in `platformio.ini`, to avoid pushing a whole library to VC.
    - Things can change and break something. Best to keep a local copy and it can be placed in `lib`.
- Simulator(Wokwi) setup
    - Wokwi has limited sets of components to choose from. ST7789 chip does not exist. So, as a workaround I used ILI9341 display. Display config is separately placed in `config/device` and `config/sim`.
    - Wokwi only has [esp32-c6-devkitc-1](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32c6/esp32-c6-devkitc-1/user_guide.html), which does not have `GPIO14` exposed whereas [esp32-c6-devkitm-1](https://docs.espressif.com/projects/esp-dev-kits/en/latest/esp32c6/esp32-c6-devkitm-1/user_guide.html) does. The Waveshare ESP32C6 board, that I'm using, has integreated 1.47inch display. The display uses `GPIO14` as Chip select pin. So, the simulator version of `tft_eSPI` library configuration uses `GPIO10` and that is what the chip select pin is connected to in the simulator.
    - Using ILI9341, made the display bigger (2.8inch) in the simulator. At the moment, I did not find any way to limit/reduce it to the size of the Waveshare board display (1.47inch). So, as a result, the simulator shows more in the display than the device itself.
