
#ifndef _OLED_SSD1306_H_
#define _OLED_SSD1306_H_

#include "Arduino.h"
#include <SPI.h>

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20
#define SSD1306_COLUMNADDR 0x21
#define SSD1306_PAGEADDR   0x22

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E

class OLED_SSD1306 {
public:
    OLED_SSD1306(int8_t DC, int8_t RST, int8_t CS);

    void begin(int width, int height, uint8_t switchvcc = SSD1306_SWITCHCAPVCC, bool reset=true);

    void invertDisplay(uint8_t i);
    void display(const uint8_t* buffer);

    void dim(boolean dim);

private:
    void ssd1306_command(uint8_t c);
    int8_t _vccstate, sid, sclk, dc, rst, cs;
    uint16_t width, height;
};

#endif /* _OLED_SSD1306_H_ */
