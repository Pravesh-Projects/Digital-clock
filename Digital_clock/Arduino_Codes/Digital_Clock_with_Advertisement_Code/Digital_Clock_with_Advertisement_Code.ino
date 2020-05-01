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
  for(int i=0;i<15;i++){
  tft.fillRect(40, 110, 250, 60, BLACK);
  t=rtc.getTime();
  tft.setRotation(1);
  tft.setCursor(50,10);
  tft.setTextColor(GREEN);
  tft.setTextSize(4);
  tft.println(rtc.getDateStr());
  if(rtc.getDOWStr()=="Monday"){
    tft.setTextColor(RED);
  }
  if(rtc.getDOWStr()=="Tuesday"){
    tft.setTextColor(BLUE);
  }
  if(rtc.getDOWStr()=="Wednesday"){
    tft.setTextColor(CYAN);
  }
  if(rtc.getDOWStr()=="Thursday"){
    tft.setTextColor(MAGENTA);
  }
  if(rtc.getDOWStr()=="Friday"){
    tft.setTextColor(YELLOW);
  }
  if(rtc.getDOWStr()=="Saturday"){
    tft.setTextColor(GREEN);
  }
  if(rtc.getDOWStr()=="Sunday"){
    tft.setTextColor(GREEN);
  }
  tft.setCursor(90,50);
  tft.setTextSize(4);
  tft.println(rtc.getDOWStr());
  tft.setCursor(5,80);
  tft.setTextColor(WHITE);
  tft.println("-------------");
  tft.setTextColor(WHITE);
  tft.setTextSize(5);
  tft.setCursor(50,120);
  tft.println(rtc.getTimeStr());
  tft.setCursor(0,170);
  tft.setTextColor(WHITE);
  tft.setTextSize(4);
  tft.println("-------------");
  tft.setCursor(60,200);
  tft.setTextColor(GREEN);
  tft.setTextSize(3);
  tft.print("Temp:");
  tft.print(rtc.getTemp());
  tft.println("C");
  delay(800);}
  tft.fillScreen(BLACK);
}


