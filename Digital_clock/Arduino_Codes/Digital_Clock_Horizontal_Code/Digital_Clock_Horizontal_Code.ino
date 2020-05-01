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
  tft.setCursor(0,20);
  
}

void loop() {
  t=rtc.getTime();
  tft.setRotation(1);
  tft.setTextColor(WHITE);
  tft.setTextSize(12);
  tft.setCursor(0,70);
  if(t.hour<10){
    tft.print("0");
    tft.print(t.hour);
  }
  else{
    tft.print(t.hour);
  }
  tft.setCursor(130,80);
  tft.setTextSize(10);
  tft.print(":");
  tft.setCursor(170,70);
  tft.setTextSize(12);
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


