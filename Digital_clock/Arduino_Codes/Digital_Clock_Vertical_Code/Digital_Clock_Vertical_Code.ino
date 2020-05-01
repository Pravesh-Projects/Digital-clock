#include <DS3231.h>
#include <Adafruit_GFX.h>
#include <Adafruit_TFTLCD.h>
#include <SPI.h>
#define LCD_CS A3
#define LCD_CD A2
#define LCD_WR A1
#define LCD_RD A0
#define LCD_RESET A4
#define BLACK   0x0000
#define BLUE    0x001F
#define RED     0xF800
#define GREEN   0x07E0
#define CYAN    0x07FF
#define MAGENTA 0xF81F
#define YELLOW  0xFFE0
#define WHITE   0xFFFF
#define BOXSIZE 40
Adafruit_TFTLCD tft(LCD_CS, LCD_CD, LCD_WR, LCD_RD, LCD_RESET);
DS3231  rtc(SDA, SCL);
Time t;
void setup() {
  rtc.begin();
  tft.reset();
  uint16_t identifier = tft.readID();
  tft.begin(identifier);
  tft.fillScreen(BLACK);  
}

void loop() {
  t=rtc.getTime();
  tft.setTextColor(WHITE);
  tft.setTextSize(18);
  tft.setCursor(15,3);
  if(t.hour<10){
    tft.print("0");
    tft.print(t.hour);
  }
  else{
    tft.print(t.hour);
  }
  tft.setCursor(67,110);
  tft.setTextSize(8);
  tft.print("..");
  tft.setCursor(15,190);
  tft.setTextSize(18);
  if(t.min<10){
    tft.print("0");
    tft.print(t.min);
  }
  else{
    tft.print(t.min);
  }
 delay(15000);
 tft.fillScreen(BLACK);
    
}


