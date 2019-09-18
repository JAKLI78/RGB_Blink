#include <Arduino.h>

#define PIN_RGB1_Red           D8  // SmartThings Capability "Color Control"  ONLY PIN CHANGE NEEDED from D5 to D8
#define PIN_RGB1_Green         D6  // SmartThings Capability "Color Control"
#define PIN_RGB1_Blue          D7  // SmartThings Capability "Color Control"
#define PIN_PUSH_BTN           D2

#define LED_CHANAL_COUNT 3

bool redOn = false;
bool greenOn = false;
bool blueOn = false;

void SetLedChanalOn();
void RgbOff();
void SetLedBrightnes();

void setup() {
  // put your setup code here, to run once:

  Serial.begin(115200);

  pinMode(PIN_RGB1_Red, OUTPUT);
  pinMode(PIN_RGB1_Green, OUTPUT);
  pinMode(PIN_RGB1_Blue, OUTPUT);
  pinMode(PIN_PUSH_BTN, INPUT);
  RgbOff();
}

void loop() {
  // put your main code here, to run repeatedly:
  int btnValue = LOW;
  btnValue = digitalRead(PIN_PUSH_BTN);
  Serial.println(btnValue);
  if (btnValue == LOW )
  {
    RgbOff();
    SetLedChanalOn(); 
    SetLedBrightnes();
    delayMicroseconds(1000);
  }
}

void RgbOff(){
  analogWrite(PIN_RGB1_Red, 0);
  analogWrite(PIN_RGB1_Green, 0);
  analogWrite(PIN_RGB1_Blue, 0);
  redOn = false;
  greenOn = false;
  blueOn = false;
}

void SetLedChanalOn(){
  for (short i = 0; i < LED_CHANAL_COUNT; i++)
  {
    short chanelNumder = random(0, 3);
    switch (chanelNumder)
    {
    case 0:
      redOn = true;
      break;
    case 1:
      greenOn = true;
      break;
    case 2:
      blueOn = true;
      break;
    default:
      break;
    }
  }
}

void SetLedBrightnes(){
  for (short i = 0; i < LED_CHANAL_COUNT; i++)
  {
    int brightnes = random(1, 1023);
    if (i == 0 && redOn)
    {
      analogWrite(PIN_RGB1_Red, brightnes);
    }
    if (i == 1 && greenOn)
    {
      analogWrite(PIN_RGB1_Green, brightnes);
    }
    if (i == 2 && blueOn)
    {
      analogWrite(PIN_RGB1_Blue, brightnes);
    }
  }
}