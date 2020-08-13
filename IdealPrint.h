#ifndef IdealPrint_h
#define IdealPrint_h

#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#define COLS 16
#define ROWS 2

class IdealPrint{
  public:
    IdealPrint(int addr) :  lcd(addr, COLS, ROWS) {};
    void init();
    void init(int delayTime);

    void displayCentered(String first_line, String second_line);
    void displayLeft(String first_line, String second_line);
    void displayRight(String first_line, String second_line);
    void displayDetail(String first_line, int col1, String second_line, int col2);

  private:
    LiquidCrystal_I2C lcd;
    int delayTime = 1500; 
};

#endif