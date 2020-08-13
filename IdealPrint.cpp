#include <Arduino.h>

#include <LiquidCrystal_I2C.h>
#include <Wire.h>

#include "IdealPrint.h"

void IdealPrint::init(){
    this->lcd.init();
    this->lcd.begin(16, 2);
    this->lcd.backlight();
    this->lcd.clear();
}

void IdealPrint::init(int delayTime){
    this->delayTime = delayTime;

    this->init();
}

void IdealPrint::displayCentered(String first_line, String second_line){
    int cols1 = 0, cols2 = 0;

    if (first_line.length() < COLS) {
        cols1 = (COLS - first_line.length()) / 2;
    }
    if (second_line.length() < COLS) {
        cols2 = (COLS - second_line.length()) / 2;
    }

    this->displayDetail(first_line, cols1, second_line, cols2);
}
    
void IdealPrint::displayLeft(String first_line, String second_line){
    this->displayDetail(first_line, 0, second_line, 0);
}
    
void IdealPrint::displayRight(String first_line, String second_line){
    int cols1 = 0, cols2 = 0;

    if (first_line.length() < COLS) {
        cols1 = COLS - first_line.length();
    }
    if (second_line.length() < COLS) {
        cols2 = COLS - second_line.length();
    }

    this->displayDetail(first_line, cols1, second_line, cols2);
}

void IdealPrint::displayDetail(String first_line, int col1, String second_line, int col2){
    int overLine1 = first_line.length() - COLS;
    int overLine2 = second_line.length() - COLS;
    
    this->lcd.clear();

    this->lcd.setCursor(col1,0);
    this->lcd.print(first_line);
    
    this->lcd.setCursor(col2,1);
    this->lcd.print(second_line);

    if ((overLine1 > 0) || (overLine2 > 0)) {
        int maiorOver = (overLine1 > overLine2) ? overLine1 : overLine2;

        for (int i = 0; i <= maiorOver; i++){
            Serial.println("Escrolando aqui \n");

            this->lcd.scrollDisplayRight();

            delay(this->delayTime);
            return;
        }
    }
    
    delay(this->delayTime);
}