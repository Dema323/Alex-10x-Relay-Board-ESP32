#include <ArduinoOTA.h>
#include <Arduino.h>
#define BLYNK_PRINT Serial

#include <WiFi.h>
#include <WiFiClient.h>
#include <BlynkSimpleEsp32.h>

char auth[] = "xxxxx";

char ssid[] = "xxxxx";
char pass[] = "xxxxx";



volatile bool pinChanged1 = false;
volatile int  pinValue1   = 0;

volatile bool pinChanged2 = false;
volatile int  pinValue2   = 0;

volatile bool pinChanged3 = false;
volatile int  pinValue3   = 0;

volatile bool pinChanged4 = false;
volatile int  pinValue4   = 0;

volatile bool pinChanged5 = false;
volatile int  pinValue5   = 0;

volatile bool pinChanged6 = false;
volatile int  pinValue6   = 0;

volatile bool pinChanged7 = false;
volatile int  pinValue7   = 0;

volatile bool pinChanged8 = false;
volatile int  pinValue8   = 0;

volatile bool pinChanged9 = false;
volatile int  pinValue9   = 0;

volatile bool pinChanged10 = false;
volatile int  pinValue10   = 0;

BlynkTimer timer;

void checkPin1()
{
  // Invert state, since button is "Active LOW"
  pinValue1 = !digitalRead(25);

  // Mark pin value changed
  pinChanged1 = true;
}

void checkPin2()
{
  pinValue2 = !digitalRead(26);

  pinChanged2 = true;
}

void checkPin3()
{
  pinValue3 = !digitalRead(27);

  pinChanged3 = true;
}

void checkPin4()
{
  pinValue4 = !digitalRead(14);

  pinChanged4 = true;
}

void checkPin5()
{
  pinValue5 = !digitalRead(12);

  pinChanged5 = true;
}

void checkPin6()
{
  pinValue6 = !digitalRead(13);

  pinChanged6 = true;
}

void checkPin7()
{
  pinValue7 = !digitalRead(15);

  pinChanged7 = true;
}

void checkPin8()
{
  pinValue8 = !digitalRead(2);

  pinChanged8 = true;
}

void checkPin9()
{
  pinValue9 = !digitalRead(0);

  pinChanged9 = true;
}

void checkPin10()
{
  pinValue10 = !digitalRead(4);

  pinChanged10 = true;
}

void setup()
{
  WiFi.mode(WIFI_STA);
  Blynk.begin(auth, ssid, pass);
  while (Blynk.connect() == false) {}
  ArduinoOTA.begin();
  pinMode(25, INPUT_PULLUP); //Pull buttonpin HIGH
  pinMode(26, INPUT_PULLUP);
  pinMode(27, INPUT_PULLUP);
  pinMode(14, INPUT_PULLUP);
  pinMode(12, INPUT_PULLUP);
  pinMode(13, INPUT_PULLUP);
  pinMode(15, INPUT_PULLUP);
  pinMode(2, INPUT_PULLUP);
  pinMode(0, INPUT_PULLUP);
  pinMode(4, INPUT_PULLUP);
  pinMode(23, OUTPUT);
  pinMode(22, OUTPUT);
  pinMode(19, OUTPUT);
  pinMode(18, OUTPUT);
  pinMode(5, OUTPUT);
  pinMode(3, OUTPUT);
  pinMode(1, OUTPUT);
  pinMode(17, OUTPUT);
  pinMode(16, OUTPUT);
  pinMode(21, OUTPUT);
attachInterrupt(digitalPinToInterrupt(25), checkPin1, CHANGE);
attachInterrupt(digitalPinToInterrupt(26), checkPin2, CHANGE);
attachInterrupt(digitalPinToInterrupt(27), checkPin3, CHANGE);
attachInterrupt(digitalPinToInterrupt(14), checkPin4, CHANGE);
attachInterrupt(digitalPinToInterrupt(12), checkPin5, CHANGE);
attachInterrupt(digitalPinToInterrupt(13), checkPin6, CHANGE);
attachInterrupt(digitalPinToInterrupt(15), checkPin7, CHANGE);
attachInterrupt(digitalPinToInterrupt(2), checkPin8, CHANGE);
attachInterrupt(digitalPinToInterrupt(0), checkPin9, CHANGE);
attachInterrupt(digitalPinToInterrupt(4), checkPin10, CHANGE);
timer.setInterval(15L, checkPin1); // Checks buttons every 250ms
timer.setInterval(15L, checkPin2);
timer.setInterval(15L, checkPin3);
timer.setInterval(15L, checkPin4);
timer.setInterval(15L, checkPin5);
timer.setInterval(15L, checkPin6);
timer.setInterval(15L, checkPin7);
timer.setInterval(15L, checkPin8);
timer.setInterval(15L, checkPin9);
timer.setInterval(15L, checkPin10);
}
void Switch1() // Blinds 1 UP (V1)
{ if (pinChanged1) {

 // Process the value
 if (pinValue1) {
   Blynk.virtualWrite(V1, HIGH);
   digitalWrite(17, LOW);
   Blynk.virtualWrite(V2, LOW);
   delay(1000);
   digitalWrite(16, HIGH);
 } else {
   Blynk.virtualWrite(V1, LOW);
   digitalWrite(16, LOW);
 }
 // Clear the mark, as we have processed the value
 pinChanged1 = false;
}
}

void Switch2() // Blinds 1 DOWN (V2)
{if (pinChanged2) {

 if (pinValue2) {
   Blynk.virtualWrite(V2, HIGH);
   digitalWrite(16, LOW);
   Blynk.virtualWrite(V1, LOW);
   delay(1000);
   digitalWrite(17, HIGH);
 } else {
   Blynk.virtualWrite(V2, LOW);
   digitalWrite(17, LOW);
 }
 pinChanged2 = false;
}
}

void Switch3() // Blinds 2 UP (V3)
{if (pinChanged3) {

 if (pinValue3) {
   Blynk.virtualWrite(V3, HIGH);
   digitalWrite(18, LOW);
   Blynk.virtualWrite(V4, LOW);
   delay(1000);
   digitalWrite(5, HIGH);
 } else {
   Blynk.virtualWrite(V3, LOW);
   digitalWrite(5, LOW);
 }
 pinChanged3 = false;
}
}

void Switch4() // Blinds 2 DOWN (V4)
{if (pinChanged4) {

 if (pinValue4) {
   Blynk.virtualWrite(V4, HIGH);
   digitalWrite(5, LOW);
   Blynk.virtualWrite(V3, LOW);
   delay(1000);
   digitalWrite(18, HIGH);
 } else {
   Blynk.virtualWrite(V4, LOW);
   digitalWrite(18, LOW);
 }
 pinChanged4 = false;
}
}

void Switch5() // Blinds 3 UP (V5)
{if (pinChanged5) {

 if (pinValue5) {
   Blynk.virtualWrite(V5, HIGH);
   digitalWrite(21, LOW);
   Blynk.virtualWrite(V6, LOW);
   delay(1000);
   digitalWrite(19, HIGH);
 } else {
   Blynk.virtualWrite(V5, LOW);
   digitalWrite(19, LOW);
 }
 pinChanged5 = false;
}
}

void Switch6() // Blinds 3 DOWN (V6)
{if (pinChanged6) {

 if (pinValue6) {
   Blynk.virtualWrite(V6, HIGH);
   digitalWrite(19, LOW);
   Blynk.virtualWrite(V5, LOW);
   delay(1000);
   digitalWrite(21, HIGH);
 } else {
   Blynk.virtualWrite(V6, LOW);
   digitalWrite(21, LOW);
 }
 pinChanged6 = false;
}
}

void Switch7() // Blinds 4 UP (V7)
{if (pinChanged7) {

 if (pinValue7) {
   Blynk.virtualWrite(V7, HIGH);
   digitalWrite(1, LOW);
   Blynk.virtualWrite(V8, LOW);
   delay(1000);
   digitalWrite(3, HIGH);
 } else {
   Blynk.virtualWrite(V7, LOW);
   digitalWrite(3, LOW);
 }
 pinChanged7 = false;
}
}

void Switch8() // Blinds 4 DOWN (V8)
{if (pinChanged8) {

 if (pinValue8) {
   Blynk.virtualWrite(V8, HIGH);
   digitalWrite(3, LOW);
   Blynk.virtualWrite(V7, LOW);
   delay(1000);
   digitalWrite(1, HIGH);
 } else {
   Blynk.virtualWrite(V8, LOW);
   digitalWrite(1, LOW);
 }
 pinChanged8 = false;
}
}

void Switch9() // BLinds 5 UP (V9)
{if (pinChanged9) {

 if (pinValue9) {
   Blynk.virtualWrite(V9, HIGH);
   digitalWrite(23, LOW);
   Blynk.virtualWrite(V10, LOW);
   delay(1000);
   digitalWrite(22, HIGH);
 } else {
   Blynk.virtualWrite(V9, LOW);
   digitalWrite(22, LOW);
 }
 pinChanged9 = false;
}
}

void Switch10()  // Blinds 5 DOWN (V10)
{if (pinChanged10) {

 if (pinValue10) {
   Blynk.virtualWrite(V10, HIGH);
   digitalWrite(22, LOW);
   Blynk.virtualWrite(V9, LOW);
   delay(1000);
   digitalWrite(23, HIGH);
 } else {
   Blynk.virtualWrite(V10, LOW);
   digitalWrite(23, LOW);
 }
 pinChanged10 = false;
}
}



BLYNK_WRITE(V1) // Blinds 1 UP
{
 if (param.asInt()){
  digitalWrite(17, LOW);
  Blynk.virtualWrite(V2, LOW);
  delay(1000);
  digitalWrite(16, HIGH);
 }else{
  digitalWrite(16, LOW);
 }
 }


BLYNK_WRITE(V2) // BLinds 1 DOWN
{
 if (param.asInt()){
  digitalWrite(16, LOW);
  Blynk.virtualWrite(V1, LOW);
  delay(1000);
  digitalWrite(17, HIGH);
 }else{
  digitalWrite(17, LOW);
 }
 }

 BLYNK_WRITE(V3) // Blinds 2 UP
 {
   if (param.asInt()){
  digitalWrite(18, LOW);
  Blynk.virtualWrite(V4, LOW);
  delay(1000);
  digitalWrite(5, HIGH);
 }else{
  digitalWrite(5, LOW);
 }
 }

 BLYNK_WRITE(V4) // Blinds 2 DOWN
 {
  if (param.asInt()){
   digitalWrite(5, LOW);
   Blynk.virtualWrite(V3, LOW);
   delay(1000);
   digitalWrite(18, HIGH);
  }else{
   digitalWrite(18, LOW);
  }
  }

  BLYNK_WRITE(V5) // Blinds 3 UP
  {
   if (param.asInt()){
    digitalWrite(21, LOW);
    Blynk.virtualWrite(V6, LOW);
    delay(1000);
    digitalWrite(19, HIGH);
   }else{
    digitalWrite(19, LOW);
   }
   }

   BLYNK_WRITE(V6) // Blinds 3 DOWN
   {
    if (param.asInt()){
     digitalWrite(19, LOW);
     Blynk.virtualWrite(V5, LOW);
     delay(1000);
     digitalWrite(21, HIGH);
    }else{
     digitalWrite(21, LOW);
    }
    }

    BLYNK_WRITE(V7) // Blinds 4 UP
    {
     if (param.asInt()){
      digitalWrite(1, LOW);
      Blynk.virtualWrite(V8, LOW);
      delay(1000);
      digitalWrite(3, HIGH);
     }else{
      digitalWrite(3, LOW);
     }
     }

     BLYNK_WRITE(V8) // Blinds 4 DOWN
     {
      if (param.asInt()){
       digitalWrite(3, LOW);
       Blynk.virtualWrite(V7, LOW);
       delay(1000);
       digitalWrite(1, HIGH);
      }else{
       digitalWrite(1, LOW);
      }
      }

      BLYNK_WRITE(V9) // Blinds 5 UP
      {
       if (param.asInt()){
        digitalWrite(23, LOW);
        Blynk.virtualWrite(V10, LOW);
        delay(1000);
        digitalWrite(22, HIGH);
       }else{
        digitalWrite(22, LOW);
       }
       }

       BLYNK_WRITE(V10) // Blinds 5 DOWN
       {
        if (param.asInt()){
         digitalWrite(22, LOW);
         Blynk.virtualWrite(V9, LOW);
         delay(1000);
         digitalWrite(23, HIGH);
        }else{
         digitalWrite(23, LOW);
        }
        }

void loop()
{
  Blynk.run();
  ArduinoOTA.handle();
  Switch1(); // Blinds 1 UP
  Switch2(); // Blinds 1 DOWN
  Switch3(); // Blinds 2 UP
  Switch4(); // Blinds 2 DOWN
  Switch5(); // Blinds 3 UP
  Switch6(); // BLinds 3 DOWN
  Switch7(); // Blinds 4 UP
  Switch8(); // Blinds 4 DOWN
  Switch9(); // Blinds 5 UP
  Switch10(); // Blinds 5 DOWN
}
