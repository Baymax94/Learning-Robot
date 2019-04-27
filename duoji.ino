#include <PS2X_lib.h>
#include <Wire.h>
#include <Adafruit_PWMServoDriver.h>
PS2X ps2x;
Adafruit_PWMServoDriver pwm = Adafruit_PWMServoDriver();
#define SERVOMIN  150
#define SERVOMAX  600

int HY=A0; //PA0

void _E5_90_8E_E9_80_80() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}

void _E5_81_9C_E6_AD_A2() {
  digitalWrite(2,LOW);
  digitalWrite(3,LOW);
  digitalWrite(4,LOW);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,LOW);
}

void _E5_89_8D_E8_BF_9B() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}

void _E5_8F_B3_E7_A7_BB() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}

void _E5_8F_B3_E8_BD_AC() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,HIGH);
  digitalWrite(7,LOW);
  digitalWrite(8,HIGH);
  digitalWrite(9,LOW);
}

void _E5_B7_A6_E7_A7_BB() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
  digitalWrite(4,HIGH);
  digitalWrite(5,LOW);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}

void _E5_B7_A6_E8_BD_AC() {
  digitalWrite(2,LOW);
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
  digitalWrite(5,HIGH);
  digitalWrite(6,LOW);
  digitalWrite(7,HIGH);
  digitalWrite(8,LOW);
  digitalWrite(9,HIGH);
}

void setup()
{
  pinMode(2, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  Serial.begin(57600);
  pwm.begin();
  ps2x.config_gamepad(12, 11,10,13, false, false);
  pwm.setPWMFreq(50);
  pinMode(HY,INPUT);
}

void loop()
{
  int HY=digitalRead(HY);
  if(HY==1){
  for (int h = 200; h <= 350; h = h + (1)) {
    pwm.setPWM(0,0,h);
    pwm.setPWM(1,0,(map(h, 200, 350, 350, 200)));
    delay(10);
  }
  for (int i = 350; i >= 200; i = i + (-1)) {
    pwm.setPWM(0,0,i);
    pwm.setPWM(1,0,(map(i, 350, 200, 200, 350)));
    delay(10);
  }
  }
  else{
  ps2x.read_gamepad(false, 0);
  if (ps2x.Button(PSB_TRIANGLE)) {
    _E5_89_8D_E8_BF_9B();
  } else if (ps2x.Button(PSB_PAD_DOWN)) {
    _E5_90_8E_E9_80_80();
  } else if (ps2x.Button(PSB_PAD_RIGHT)) {
    _E5_8F_B3_E8_BD_AC();
  } else if (ps2x.Button(PSB_PAD_LEFT)) {
    _E5_B7_A6_E8_BD_AC();
  } else if (ps2x.Button(PSB_SQUARE)) {
    _E5_8F_B3_E7_A7_BB();
  } else if (ps2x.Button(PSB_CIRCLE)) {
    _E5_B7_A6_E7_A7_BB();
  } else {
    _E5_81_9C_E6_AD_A2();
  }
  delay(100);
  }
}
