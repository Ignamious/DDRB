/* All Posible Hex of Cards using MCP23008 With Address. Adress is:

| 0 | 1 | 0 | 0 | A2 | A1 | A0 | r/w |

Full Hex  -   Board Address
0x40      -   000
0x42      -   001
0x44      -   010
0x46      -   011
0x48      -   100
0x4A      -   101
0x4C      -   110
0x4E      -   111


*/




//ADDRESS DEFS OF I2C IO EXPANDERS.
const byte SUB_OHM_BOARD_ADDRESS = 0x40;
const byte FISRT_BYTE_BOARD_ADDRESS = 0x42;
const byte SECOND_BYTE_BOARD_ADDRESS = 0x44;
const byte THIRD_BYTE_BOARD_ADDRESS = 0x46;
const byte FOURTH_BYTE_BOARD_ADDRESS = 0x48;
const byte FIRST_EXP_BOARD_ADDRESS = 0x4A;
const byte SECOND_EXP_BOARD_ADDRESS = 0x4C;
const byte MATRIX_BUTTON_4X4 = 0x4E;

//If using a different LCD then 16x4 code will need to be changed to account for it.
//Use following defs to change values as needed. Program will require at min a 16x2 screen.
//Note however that ROW 1 and 2 are used on the base and 3/4 are reserved for EX cards 1/2 (not implemented yet)
//However the options will utilise ROW 3/4 as well as the Cal check

//PIN DEFS FOR LCD 1
const byte LCD1_RS_PIN = 1;
const byte LCD1_Enable_Pin = 2;
const byte LCD1_D4_PIN = 3;
const byte LCD1_D5_PIN = 4;
const byte LCD1_D6_PIN = 5;
const byte LCD1_D7_PIN = 6;
const byte LCD1_COLUMN_COUNT = 16;
const byte LCD1_ROW_COUNT = 4;

/*
//PIN DEFS FOR LCD 2 (IF USED REMOVE COMMENT BLOCK)
const byte LCD2_RS_PIN = 1;
const byte LCD2_Enable_Pin = 2;
const byte LCD2_D4_PIN = 3;
const byte LCD2_D5_PIN = 4;
const byte LCD2_D6_PIN = 5;
const byte LCD2_D7_PIN = 6;
const byte LCD2_COLUMN_COUNT = 16;
const byte LCD2_ROW_COUNT = 4;
*/

#include <Wire.h>
#include <LiquidCrystal.h>

//OBJECT SETUP
LiquidCrystal MAIN_LCD(LCD1_RS_PIN, LCD1_Enable_Pin, LCD1_D4_PIN, LCD1_D5_PIN, LCD1_D6_PIN, LCD1_D7_PIN);

void setup() {
  // put your setup code here, to run once:
  Wire.begin();
  MAIN_LCD.begin(LCD1_COLUMN_COUNT, LCD1_ROW_COUNT);

  STARTUPSEQUINCE();
}

void loop() {
  // put your main code here, to run repeatedly:

}

void MAINLCDPREP() {
  MAIN_LCD.clear();
  MAIN_LCD.noAutoscroll();
  MAIN_LCD.setCursor(0, 0);
  MAIN_LCD.print("LOADING PREFS");
}

void CALIBRATION_CHECK() {
  MAIN_LCD.clear();
  MAIN_LCD.noAutoscroll();
  MAIN_LCD.setCursor(0, 0);
  MAIN_LCD.print("CAL CHECK:");
  MAIN_LCD.setCursor(0, 1);
  MAIN_LCD.print("ZERO DMM");
  MAIN_LCD.setCursor(0, 2);
  MAIN_LCD.print("INSERT LEADS");
  MAIN_LCD.setCursor(0, 3);
  MAIN_LCD.print("PRESS # TO CONT");
  while (1) {
    //wait for # to be pressed code
  }


}

void STARTUPSEQUINCE() {
  MAINLCDPREP();
  ZERO_ALL_RELAYS();
}

void ZERO_ALL_RELAYS() {
  Wire.beginTransmission(SUB_OHM_BOARD_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(FISRT_BYTE_BOARD_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(SECOND_BYTE_BOARD_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(THIRD_BYTE_BOARD_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
  Wire.beginTransmission(FOURTH_BYTE_BOARD_ADDRESS);
  Wire.write(0x00);
  Wire.endTransmission();
}

void FIRST_STARTUP() {
  MAIN_LCD.clear();
  MAIN_LCD.noAutoscroll();
  MAIN_LCD.setCursor(0, 0);
  MAIN_LCD.print("FIRST STARTUP");
  CALIBRATION_CHECK(); 

}

