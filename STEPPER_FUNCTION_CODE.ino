#include <Wire.h>
#define DEVICE_ID_1 1        //eeprom address
#define DEVICE_ID_1_SIZE 30  //eeprom address size

#define ENCODER_SENSOR_ONE 5        //limit stwich 1
#define ENCODER_SENSOR_TWO 2        //limit stwich 2
#define ENCODER_SENSOR_LIMIT_ONE 7  //down
#define ENCODER_SENSOR_LIMIT_TWO 4  //up
#define DIRPIN 3
#define STEPPIN 6
#define BACKWORD 12
#define FORWORD 9
#define HOME_LOCATION 10
#define START_LOCARION 8
#define START_PROCESS_LOCARION 13
#define FUSHER_BORD_READ A0
#define STEPPER_BORD_WRITE 11
#define SIGNAL_LIGHT A1
#define FIRST_LOCATON A2


int ENCODER_SENSOR_ONE_VALUE = 0;
int ENCODER_SENSOR_TWO_VALUE = 0;
int ENCODER_SENSOR_LIMIT_ONE_VALUE = 0;
int ENCODER_SENSOR_LIMIT_TWO_VALUE = 0;
int BACKWORD_VALUE = 0;
int FORWORD_VALUE = 0;
int HOME_LOCATION_VALUE = 0;
int START_LOCARION_VALUE = 0;
int DATA_RESVIE_VALUE = 0;
int PRESTSTE_ZERO = 0;
int PRESTSTE = 0;
int PRESTSTE_TWO = 0;
int COUNT_VALUE = 0;
int START_LOCARION_VALUE_COUNT = 0;
int GAP = 0;
int TRAY_GAP_VALUE_NEW = 0;
int COUNT_VALUE_STOP = 0;
int START_PROCESS_LOCARION_VALUE = 0;
float STEPPER_COUNT = 0;
int TRAY_GAP_VALUE = 0;
int FUSHER_BORD_READ_VALUE = 0;
int FIRST_LOCATON_VALUE = 0;


int STATUS = 0;
int STATUS_ONE = 0;
int COUNT = 0;
int COUNT_ONE = 0;
int COUNT_TWO = 0;
int COUNT_THREE = 0;
int LOCATION = 0;
int S_LOCATION = 0;
int STATUS_THREE = 0;
int STATUS_SIX = 0;
int FIRST_LOCATION_OK = 0;
int STEP = 0;

int TRAY_COUNT = 0;
int COUNT_VALUE_NEW = 0;

int STEPPER_COUNT_NEW = 3060;

void setup() {
  Wire.begin(DEVICE_ID_1);
  Serial.begin(9600);
  Wire.onReceive(RECEIVE_EVENT);
  pinMode(ENCODER_SENSOR_ONE, INPUT);
  pinMode(ENCODER_SENSOR_TWO, INPUT);
  pinMode(ENCODER_SENSOR_LIMIT_ONE, INPUT);
  pinMode(ENCODER_SENSOR_LIMIT_TWO, INPUT);
  pinMode(BACKWORD, INPUT);
  pinMode(FORWORD, INPUT);
  pinMode(HOME_LOCATION, INPUT);
  pinMode(START_LOCARION, INPUT);
  pinMode(DIRPIN, OUTPUT);
  pinMode(STEPPIN, OUTPUT);
  pinMode(START_PROCESS_LOCARION, INPUT);
  pinMode(FUSHER_BORD_READ, INPUT);
  pinMode(STEPPER_BORD_WRITE, OUTPUT);
  pinMode(SIGNAL_LIGHT, OUTPUT);
  //digitalWrite(STEPPER_BORD_WRITE, 1);
  pinMode(FIRST_LOCATON, INPUT);
}
void RECEIVE_EVENT() {
  String response = "";
  while (1 <= Wire.available()) {
    char b = Wire.read();
    response += b;
  }
  String TRAY_GAP = response.substring(0, 2);
  TRAY_GAP_VALUE = TRAY_GAP.toInt();
  //TRAY_GAP_VALUE = 1;
  //<-------------------------------me code aka hari------------------------->5mm---83
  if (TRAY_GAP_VALUE == 1) {
    STEPPER_COUNT = 200;  //20=1mm
  } else if (TRAY_GAP_VALUE == 2) {
    STEPPER_COUNT = 400;
  } else if (TRAY_GAP_VALUE == 3) {
    STEPPER_COUNT = 600;
  } else if (TRAY_GAP_VALUE == 4) {
    STEPPER_COUNT = 800;
  } else if (TRAY_GAP_VALUE == 5) {
    STEPPER_COUNT = 1000;
  } else if (TRAY_GAP_VALUE == 6) {
    STEPPER_COUNT = 1200;
  } else if (TRAY_GAP_VALUE == 7) {
    STEPPER_COUNT = 1400;
  } else if (TRAY_GAP_VALUE == 8) {
    STEPPER_COUNT = 1600;
  } else if (TRAY_GAP_VALUE == 9) {
    STEPPER_COUNT = 1800;
  } else if (TRAY_GAP_VALUE == 10) {
    STEPPER_COUNT = 2000;
  } else if (TRAY_GAP_VALUE == 51) {
    STEPPER_COUNT = 1;
  } else if (TRAY_GAP_VALUE == 52) {
    STEPPER_COUNT = 2;
  } else if (TRAY_GAP_VALUE == 53) {
    STEPPER_COUNT = 3;
  } else if (TRAY_GAP_VALUE == 54) {
    STEPPER_COUNT = 4;
  } else if (TRAY_GAP_VALUE == 55) {
    STEPPER_COUNT = 5;
  } else if (TRAY_GAP_VALUE == 56) {
    STEPPER_COUNT = 6;
  } else if (TRAY_GAP_VALUE == 57) {
    STEPPER_COUNT = 7;
  } else if (TRAY_GAP_VALUE == 58) {
    STEPPER_COUNT = 8;
  } else if (TRAY_GAP_VALUE == 59) {
    STEPPER_COUNT = 9;
  } else if (TRAY_GAP_VALUE == 60) {
    STEPPER_COUNT = 10;
  } else if (TRAY_GAP_VALUE == 61) {
    STEPPER_COUNT = 11;
  } else if (TRAY_GAP_VALUE == 62) {
    STEPPER_COUNT = 12;
  } else if (TRAY_GAP_VALUE == 63) {
    STEPPER_COUNT = 13;
  } else if (TRAY_GAP_VALUE == 64) {
    STEPPER_COUNT = 14;
  } else if (TRAY_GAP_VALUE == 65) {
    STEPPER_COUNT = 15;
  } else if (TRAY_GAP_VALUE == 66) {
    STEPPER_COUNT = 16;
  } else if (TRAY_GAP_VALUE == 67) {
    STEPPER_COUNT = 17;
  } else if (TRAY_GAP_VALUE == 68) {
    STEPPER_COUNT = 18;
  } else if (TRAY_GAP_VALUE == 69) {
    STEPPER_COUNT = 19;
  } else if (TRAY_GAP_VALUE == 70) {
    STEPPER_COUNT = 20;
  }
  //Serial.println(TRAY_GAP_VALUE);
  //<-------------------------------me code aka hari------------------------->

  //STEPPER_COUNT = (TRAY_GAP_VALUE * 100) + (TRAY_GAP_VALUE + 2);  //(1*900+1+2)*9=8127
  //STEPPER_COUNT = TRAY_GAP_VALUE_NEW * 83;  //(1*900+1+2)*9=8127
  //STEPPER_COUNT = TRAY_GAP_VALUE * 380;  //(1*900+1+2)*9=8127
  // Serial.println(STEPPER_COUNT);
}
void loop() {
  ENCODER_SENSOR_ONE_VALUE = digitalRead(ENCODER_SENSOR_ONE);
  ENCODER_SENSOR_TWO_VALUE = digitalRead(ENCODER_SENSOR_TWO);
  ENCODER_SENSOR_LIMIT_ONE_VALUE = digitalRead(ENCODER_SENSOR_LIMIT_ONE);  //
  ENCODER_SENSOR_LIMIT_TWO_VALUE = digitalRead(ENCODER_SENSOR_LIMIT_TWO);
  BACKWORD_VALUE = digitalRead(BACKWORD);
  FORWORD_VALUE = digitalRead(FORWORD);
  HOME_LOCATION_VALUE = digitalRead(HOME_LOCATION);
  START_LOCARION_VALUE = digitalRead(START_LOCARION);  //cahnge locating select test
  START_PROCESS_LOCARION_VALUE = digitalRead(START_PROCESS_LOCARION);
  FUSHER_BORD_READ_VALUE = analogRead(FUSHER_BORD_READ);
  FIRST_LOCATON_VALUE = analogRead(FIRST_LOCATON);

  // Serial.print("\t");
  /* Serial.print("ENCODER_SENSOR_LIMIT_ONE_VALUE :-");
  Serial.print(ENCODER_SENSOR_LIMIT_ONE_VALUE);
  Serial.print("\t");
  Serial.print("ENCODER_SENSOR_LIMIT_TWO_VALUE :-");
  Serial.print(ENCODER_SENSOR_LIMIT_TWO_VALUE);
  Serial.print("\t");
  Serial.print("BACKWORD_VALUE :-");
  Serial.print(BACKWORD_VALUE);
  Serial.print("\t");
  Serial.print("FORWORD_VALUE :-");
  Serial.print(FORWORD_VALUE);
  Serial.print("\t");
  Serial.print("HOME_LOCATION_VALUE :-");
  Serial.print(HOME_LOCATION_VALUE);
  Serial.print("\t");
  Serial.print("START_LOCARION_VALUE :-");
  Serial.print(START_LOCARION_VALUE);*/
  //Serial.print(FUSHER_BORD_READ_VALUE);
  //Serial.println("\t");

  //<---------------udata manual------------------>
  if (FORWORD_VALUE == 1 && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
    DRIVER_FORWORD();  //udata
    STATUS = 0;
  }
  if (BACKWORD_VALUE == 1 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
    DRIVER_BACKWORD_TWO();  //yatata
    STATUS = 0;
  }
  //<--------------------------------->DRIVER_FORWORD_NOMAL(){}DRIVER_BACKWORD_TWO_NOMAL(){}
  //<------------------home--------------->
  if (HOME_LOCATION_VALUE == 1) {
    STATUS = 1;
  } else if (STATUS == 1 && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
    DRIVER_FORWORD_TWO();  //udata
  } else if (STATUS == 1 && ENCODER_SENSOR_LIMIT_TWO_VALUE == 1) {
    STATUS = 2;
  } else if (STATUS == 2 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
    DRIVER_BACKWORD_TWO();  //yatata
  } else if (STATUS == 2 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
    digitalWrite(STEPPER_BORD_WRITE, 1);
    COUNT_VALUE_NEW = 0;
    COUNT_VALUE = 0;
    STATUS = 0;
    STATUS_THREE = 1;
    STEP = 1;
  }
  //<----------------------------------------->
  if (START_PROCESS_LOCARION_VALUE == 1) {
    digitalWrite(STEPPER_BORD_WRITE, 0);
  }

  //<------------------count up--------------->
  if (STATUS_ONE == 0) {
    if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 0) {
      COUNT = COUNT + 1;
      STATUS_ONE = 1;
    }
  } else if (STATUS_ONE == 1) {
    if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 0) {
      COUNT_ONE = COUNT_ONE + 1;
      STATUS_ONE = 2;
    }
  } else if (STATUS_ONE == 2) {
    if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 1) {
      COUNT_TWO = COUNT_TWO + 1;
      STATUS_ONE = 3;
    }
  } else if (STATUS_ONE == 3) {
    if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 1) {
      COUNT_THREE = COUNT_THREE + 1;
      STATUS_ONE = 0;
    }
  }
  //< ------------------------------------->
  //<--------------------------------------------------------------------->

  //<-------------------location select manual---------------->
  if (START_LOCARION_VALUE == 1 && PRESTSTE == 1) {
    if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 0) {
      LOCATION = 1;
      COUNT = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 0) {
      LOCATION = 2;
      COUNT_ONE = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 1) {
      LOCATION = 3;
      COUNT_TWO = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 1) {
      LOCATION = 4;
      COUNT_THREE = 0;
    }
    PRESTSTE = 2;
    COUNT_VALUE++;
  } else if (START_LOCARION_VALUE == 0) {
    PRESTSTE = 1;
  }
  //<--------------------------------------------------------------------->
  //<-------------------location select automatic---------------->
  if (FUSHER_BORD_READ_VALUE >= 500 && PRESTSTE_TWO == 1) {
    if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 0) {
      LOCATION = 1;
      COUNT = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 0) {
      LOCATION = 2;
      COUNT_ONE = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 1) {
      LOCATION = 3;
      COUNT_TWO = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 1) {
      LOCATION = 4;
      COUNT_THREE = 0;
    }
    PRESTSTE_TWO = 2;
    COUNT_VALUE++;
  } else if (FUSHER_BORD_READ_VALUE <= 499) {
    PRESTSTE_TWO = 1;
  }
  //<-----------------------bord okkoma pirunama pahalata yana aka--------------------------->
  if (TRAY_GAP_VALUE == 1) {
    COUNT_VALUE_NEW = COUNT_VALUE * 1;
    if (COUNT_VALUE_NEW == 50) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 2) {
    COUNT_VALUE_NEW = COUNT_VALUE * 2;
    if (COUNT_VALUE_NEW == 50) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 3) {
    COUNT_VALUE_NEW = COUNT_VALUE * 3;
    if (COUNT_VALUE_NEW == 51) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 4) {
    COUNT_VALUE_NEW = COUNT_VALUE * 4;
    if (COUNT_VALUE_NEW == 52) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 5) {
    COUNT_VALUE_NEW = COUNT_VALUE * 5;
    if (COUNT_VALUE_NEW == 50) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 6) {
    COUNT_VALUE_NEW = COUNT_VALUE * 6;
    if (COUNT_VALUE_NEW == 54) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 7) {
    COUNT_VALUE_NEW = COUNT_VALUE * 7;
    if (COUNT_VALUE_NEW == 56) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 8) {
    COUNT_VALUE_NEW = COUNT_VALUE * 8;
    if (COUNT_VALUE_NEW == 56) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 9) {
    COUNT_VALUE_NEW = COUNT_VALUE * 9;
    if (COUNT_VALUE_NEW == 54) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }

  if (TRAY_GAP_VALUE == 10) {
    COUNT_VALUE_NEW = COUNT_VALUE * 10;
    if (COUNT_VALUE_NEW == 50) {
      COUNT_VALUE_STOP = 1;
      if (ENCODER_SENSOR_LIMIT_ONE_VALUE == 0) {
        DRIVER_BACKWORD_TWO();  //yatata
                                //<-----------------atrm on  and motor off,fusher off,stop on--------->
        STATUS = 6;
      } else if (STATUS == 6 && ENCODER_SENSOR_LIMIT_ONE_VALUE == 1) {
        DRIVER_STOP_AND_SIGNAL_LIGHT();
        //<-----------------atrm on  and motor off,fusher off,stop on--------->
        COUNT_VALUE_NEW = 0;
        COUNT_VALUE = 0;
        STATUS = 0;
      }
    } else {
      COUNT_VALUE_STOP = 0;
    }
  }
  //<-------------------------------------------------->
  //<----------------------LOCATION RUN---------------->
  if (LOCATION == 1) {
    if (STEPPER_COUNT > COUNT && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0 && COUNT_VALUE_STOP == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else if (STEPPER_COUNT > COUNT && ENCODER_SENSOR_LIMIT_TWO_VALUE == 1) {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    } else {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    }
  }

  else if (LOCATION == 2) {
    if (STEPPER_COUNT > COUNT_ONE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0 && COUNT_VALUE_STOP == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else if (STEPPER_COUNT > COUNT_ONE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 1) {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    } else {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    }
  }

  else if (LOCATION == 3) {
    if (STEPPER_COUNT > COUNT_TWO && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0 && COUNT_VALUE_STOP == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else if (STEPPER_COUNT > COUNT_TWO && ENCODER_SENSOR_LIMIT_TWO_VALUE == 1) {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    } else {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    }
  }

  else if (LOCATION == 4) {
    if (STEPPER_COUNT > COUNT_THREE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0 && COUNT_VALUE_STOP == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else if (STEPPER_COUNT > COUNT_THREE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 1) {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    } else {
      DRIVER_STOP();
      STATUS = 0;
      STATUS_ONE = 0;
      LOCATION = 0;
    }
  }
  //< -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- -- --->

  //<-------------------first location step---------------->
  if (FIRST_LOCATON_VALUE == 1023 && PRESTSTE_ZERO == 1) {
    if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 0) {
      S_LOCATION = 1;
      COUNT = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 0) {
      S_LOCATION = 2;
      COUNT_ONE = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 1 && ENCODER_SENSOR_TWO_VALUE == 1) {
      S_LOCATION = 3;
      COUNT_TWO = 0;
    } else if (ENCODER_SENSOR_ONE_VALUE == 0 && ENCODER_SENSOR_TWO_VALUE == 1) {
      S_LOCATION = 4;
      COUNT_THREE = 0;
    }
    PRESTSTE_ZERO = 2;
  } else if (FIRST_LOCATON_VALUE == 0) {
    PRESTSTE_ZERO = 1;
  }

  if (S_LOCATION == 1) {
    if (STEPPER_COUNT_NEW > COUNT && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
      DRIVER_FORWORD();
      STATUS = 0;

    } else {
      DRIVER_STOP();
      FIRST_LOCATION_OK = 1;
      STATUS = 0;
      STATUS_ONE = 0;
      S_LOCATION = 0;
    }
  }

  else if (S_LOCATION == 2) {
    if (STEPPER_COUNT_NEW > COUNT_ONE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else {
      DRIVER_STOP();
      FIRST_LOCATION_OK = 1;
      STATUS = 0;
      STATUS_ONE = 0;
      S_LOCATION = 0;
    }
  }

  else if (S_LOCATION == 3) {
    if (STEPPER_COUNT_NEW > COUNT_TWO && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else {
      DRIVER_STOP();
      FIRST_LOCATION_OK = 1;
      STATUS = 0;
      STATUS_ONE = 0;
      S_LOCATION = 0;
    }
  }

  else if (S_LOCATION == 4) {
    if (STEPPER_COUNT_NEW > COUNT_THREE && ENCODER_SENSOR_LIMIT_TWO_VALUE == 0) {
      DRIVER_FORWORD();
      STATUS = 0;
    } else {
      DRIVER_STOP();
      FIRST_LOCATION_OK = 1;
      STATUS = 0;
      STATUS_ONE = 0;
      S_LOCATION = 0;
    }
  }
}
void DRIVER_FORWORD() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(250);
}
void DRIVER_FORWORD_TWO() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(180);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(180);
}
void DRIVER_BACKWORD() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
}
void DRIVER_BACKWORD_TWO() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(160);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  delayMicroseconds(160);
}
void DRIVER_STOP() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 0);
  // analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(300);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 0);
  //analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(300);
}
void DRIVER_FORWORD_NOMAL() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  //analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  //analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
}
void DRIVER_BACKWORD_TWO_NOMAL() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  // analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  // analogWrite(SIGNAL_LIGHT, 0);
  delayMicroseconds(250);
}
//////////////////////////////////////
void DRIVER_FORWORD_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  // analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  // analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
}
void DRIVER_FORWORD_TWO_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
}
void DRIVER_BACKWORD_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
}
void DRIVER_BACKWORD_TWO_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(200);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 1);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(200);
}
void DRIVER_STOP_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 0);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(300);
  digitalWrite(STEPPIN, LOW);
  digitalWrite(STEPPER_BORD_WRITE, 0);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(300);
}
void DRIVER_FORWORD_NOMAL_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, HIGH);
  digitalWrite(STEPPIN, HIGH);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
}
void DRIVER_BACKWORD_TWO_NOMAL_AND_SIGNAL_LIGHT() {
  digitalWrite(DIRPIN, LOW);
  digitalWrite(STEPPIN, HIGH);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
  digitalWrite(STEPPIN, LOW);
  //analogWrite(SIGNAL_LIGHT, 1023);
  delayMicroseconds(250);
}