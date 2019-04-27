int carstop=2; //PA0
int go=11; //PA1
int back=12; //PA2
int turnleft=A0; //PA3
int turnright=A1; //PA4
int shiftleft=A2; //PA5
int shiftright=A3; //PA6
void setup() {
  // put your setup code here, to run once:
  //初始化串口，9600波特率
  Serial.begin(9600); 
  //定义输入引脚
  pinMode(carstop,INPUT);
  pinMode(go,INPUT);
  pinMode(back,INPUT);
  pinMode(turnleft,INPUT);
  pinMode(turnright,INPUT);
  pinMode(shiftleft,INPUT);
  pinMode(shiftright,INPUT);
  //定义输出引脚
  pinMode(3, OUTPUT);
  pinMode(4, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(6, OUTPUT);
  pinMode(7, OUTPUT);
  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  
}

void loop() {
  // put your main code here, to run repeatedly:
  int HYstop=digitalRead(carstop);
  int HYgo=digitalRead(go);
  int HYback=digitalRead(back);
  int HYtl=digitalRead(turnleft);
  int HYtr=digitalRead(turnright);
  int HYsl=digitalRead(shiftleft);
  int HYsr=digitalRead(shiftright);
  if(HYstop==1){
    digitalWrite(3,LOW);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,LOW);
    delay(100);  
  }
  else if(HYstop==0 && HYgo==1){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(100); 
  }
  else if(HYstop==0 && HYback==1){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    delay(100);
  }
  else if(HYstop==0 && HYtl==1){
    delay(100);
  }
  else if(HYstop==0 && HYtr==1){
    delay(100);
  }
  else if(HYstop==0 && HYsl==1){
    digitalWrite(3,LOW);
    digitalWrite(4,HIGH);
    digitalWrite(5,LOW);
    digitalWrite(6,HIGH);
    digitalWrite(7,HIGH);
    digitalWrite(8,LOW);
    digitalWrite(9,HIGH);
    digitalWrite(10,LOW);
    delay(100);
  }
  else if(HYstop==0 && HYsr==1){
    digitalWrite(3,HIGH);
    digitalWrite(4,LOW);
    digitalWrite(5,HIGH);
    digitalWrite(6,LOW);
    digitalWrite(7,LOW);
    digitalWrite(8,HIGH);
    digitalWrite(9,LOW);
    digitalWrite(10,HIGH);
    delay(100);
  }
  /*
  Serial.println(HYstop);
  Serial.println(HYgo);
  Serial.println(HYback);
  Serial.println(HYtl);
  Serial.println(HYtr);
  Serial.println(HYsl);
  Serial.println(HYsr);
  */
  // 延迟大小决定循环读取的时间间隔 
  delay(100);
}
