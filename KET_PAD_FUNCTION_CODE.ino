#include <EEPROM.h>
#include <Wire.h>
#include <LiquidCrystal_I2C.h>
#include <Keypad.h>
#include <SPI.h>

LiquidCrystal_I2C lcd(0x27, 16, 2);
const int ROW_NUM = 4;
const int COLUMN_NUM = 4;
char keys[ROW_NUM][COLUMN_NUM] = {
  { '7', '8', '9', 'A' },
  { '4', '5', '6', 'B' },
  { '1', '2', '3', 'D' },
  { 'C', '0', 'F', 'E' }
};
byte pin_rows[ROW_NUM] = { 2, 3, 4, 5 };
byte pin_column[COLUMN_NUM] = { 6, 7, 8, 9 };
Keypad keypad = Keypad(makeKeymap(keys), pin_rows, pin_column, ROW_NUM, COLUMN_NUM);

int cursorColum = 0;
int count = 0;
String KEy;

int KEY_PAD_ON;
int ADDRESS_ONE = 0;
int ADDRESS_TWO = 0;
int ADDRESS_THREE = 0;
int ADDRESS_FORE = 0;
int address = 0;

#define DEVICE_ID_1 1
#define DEVICE_ID_2 2
#define DEVICE_ID_3 3
#define DEVICE_ID_4 5

#define DEVICE_1_SIZE 30
#define DEVICE_2_SIZE 30
#define DEVICE_3_SIZE 30
#define DEVICE_4_SIZE 30

void setup() {
  while (!Serial) {
    ;
  }
  ADDRESS_ONE = EEPROM.read(0);
  ADDRESS_TWO = EEPROM.read(1);
  ADDRESS_THREE = EEPROM.read(2);
  ADDRESS_FORE = EEPROM.read(3);

  Serial.begin(9600);
  Wire.begin();
  Serial.print(ADDRESS_ONE + 1000);
  Serial.print("\t");
  Serial.print(ADDRESS_TWO + 1000);
  Serial.print("\t");
  Serial.print(ADDRESS_THREE + 1000);
  Serial.print("\t");
  Serial.println(ADDRESS_FORE + 1000);

  String ADDRESS_ONE_FINAL_RESALT = String(ADDRESS_ONE);
  char* COMMUNICATION_WORD_ADDESS_ONE = &ADDRESS_ONE_FINAL_RESALT[0];
  Wire.beginTransmission(DEVICE_ID_1);
  Wire.write(COMMUNICATION_WORD_ADDESS_ONE);
  Wire.endTransmission();

  String ADDRESS_TWO_FINAL_RESALT = String(ADDRESS_TWO);
  char* COMMUNICATION_WORD_ADDESS_TWO = &ADDRESS_TWO_FINAL_RESALT[0];
  Wire.beginTransmission(DEVICE_ID_2);
  Wire.write(COMMUNICATION_WORD_ADDESS_TWO);
  Wire.endTransmission();

  String ADDRESS_THREE_FINAL_RESALT = String(ADDRESS_THREE);
  char* COMMUNICATION_WORD_ADDESS_THREE = &ADDRESS_THREE_FINAL_RESALT[0];
  Wire.beginTransmission(DEVICE_ID_3);
  Wire.write(COMMUNICATION_WORD_ADDESS_THREE);
  Wire.endTransmission();

  String ADDRESS_FORE_FINAL_RESALT = String(ADDRESS_FORE);
  char* COMMUNICATION_WORD_ADDESS_FORE = &ADDRESS_FORE_FINAL_RESALT[0];
  Wire.beginTransmission(DEVICE_ID_4);
  Wire.write(COMMUNICATION_WORD_ADDESS_FORE);
  Wire.endTransmission();

  lcd.init();
  lcd.init();
  lcd.backlight();
  lcd.print("Unloder Machine");
}
void loop() {
  char key = keypad.getKey();
  if (key) {
    lcd.print(key);
    String KEY = String(key);
    if (count < 17) {
      KEy = KEy + key;
    }
  }
  if (key == 'A') {
    lcd.clear();
    delay(10);
    lcd.print("Tray Gap :-");
    address = 0;
  } else if (key == 'B') {
    lcd.clear();
    delay(10);
    lcd.print("---- :-");
    address = 1;
  } else if (key == 'D') {
    lcd.clear();
    delay(10);
    lcd.print("---- :-");
    address = 2;
  } else if (key == 'E') {
    lcd.clear();
    delay(10);
    lcd.print("FL:-");
    address = 3;
  } else if (key == 'C') {
    lcd.clear();
    KEy = "";
    Serial.print(KEy);
    delay(100);
    lcd.clear();
    lcd.print("Unloder Machine");
  } else if (key == 'F') {
    lcd.clear();
    delay(100);
    lcd.print("Loading.");
    delay(250);
    lcd.clear();
    lcd.print("Loading..");
    delay(250);
    lcd.clear();
    lcd.print("Loading...");
    delay(250);
    lcd.clear();
    lcd.print("Loading....");
    delay(250);
    lcd.clear();
    lcd.print("Loading.....");
    delay(250);
    lcd.clear();
    lcd.print("Loading......");
    delay(250);
    lcd.clear();
    lcd.print("Loading.......");
    delay(250);
    lcd.clear();
    lcd.print("Loading.........");
    delay(250);
    lcd.clear();
    lcd.print("Loading.........");
    delay(250);
    lcd.clear();
    int Address = address;
    String key_key = KEy.substring(1, KEy.length() - 1);
    float Key_Key = key_key.toInt();
    EEPROM.write(Address, Key_Key);
    lcd.print("Click (c)");
  }
}