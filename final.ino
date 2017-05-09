#include <LiquidCrystal.h>
LiquidCrystal lcd(12, 11, 10, 9, 3, A0);
#define S0 4
#define S1 5
#define S2 6
#define S3 7
#define sensorOut 8
int frequencyR = 0;
int frequencyG =0;
int frequencyB = 0;
const int ledPin = 13;
const int buttonPin = 2;
volatile int buttonState = 0;
int valR[] = {0,0,0};
int valG[] = {0,0,0};
int valB[] = {0,0,0};
int aveR ;int aveG; int aveB;
int n = 0;

void setup() {
  lcd.begin(16,2);
  pinMode(ledPin, OUTPUT);
  pinMode(S0, OUTPUT);
  pinMode(S1, OUTPUT);
  pinMode(S2, OUTPUT);
  pinMode(S3, OUTPUT);
  pinMode(sensorOut, INPUT);
  pinMode(buttonPin, INPUT);
  attachInterrupt(0,pin_ISR, CHANGE);
 
  
  // Setting frequency-scaling to 20%
  digitalWrite(S0,HIGH);
  digitalWrite(S1,LOW);
  
  Serial.begin(9600);
    
}
void loop(){

}

void pin_ISR() {
  buttonState = digitalRead(buttonPin);
  digitalWrite(ledPin,buttonState);
  // Setting red filtered photodiodes to be read
  while(n<3){
  digitalWrite(S2,LOW);
  digitalWrite(S3,LOW);
  // Reading the output frequency
  frequencyR = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyR = map(frequencyR, 25,72,255,0);
  // Printing the value on the serial monitor
  Serial.print("R= ");//printing name
  Serial.print(frequencyR);//printing RED color frequency
  Serial.print("  ");
  //delay(100);
  // Setting Green filtered photodiodes to be read
  digitalWrite(S2,HIGH);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyG = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyG = map(frequencyG, 30,90,255,0);
  // Printing the value on the serial monitor

  Serial.print("G= ");//printing name
  Serial.print(frequencyG);//printing RED color frequency
  Serial.print("  ");
  //delay(100);
  // Setting Blue filtered photodiodes to be read
  digitalWrite(S2,LOW);
  digitalWrite(S3,HIGH);
  // Reading the output frequency
  frequencyB = pulseIn(sensorOut, LOW);
  //Remaping the value of the frequency to the RGB Model of 0 to 255
  frequencyB = map(frequencyB, 25,70,255,0);
  // Printing the value on the serial monitor

  Serial.print("B= ");//printing name
  Serial.print(frequencyB);//printing RED color frequency
  Serial.println("  ");
  delay(100);
  valR[n] = frequencyR;
  valG[n] = frequencyG;
  valB[n] = frequencyB;
  n = n+1;
  delay(1000);
  }
  aveR = (valR[0] + valR[1] + valR[2])/3;
  aveG = (valG[0] + valG[1] + valG[2])/3;
  aveB = (valB[0] + valB[1] + valB[2])/3;
  Serial.print("aveR= ");
  Serial.println(aveR);
    Serial.print("aveG= ");
  Serial.println(aveG);
    Serial.print("aveB= ");
  Serial.println(aveB);
  n = 0;
  lcd.clear();
  if (frequencyR > 180 && frequencyR<220 && frequencyG > 170 && frequencyG < 210 && frequencyB >190 && frequencyB < 230 ){
   Serial.println("Ph = 4");
   lcd.setCursor(0,1);
   lcd.print("Ph is 4");
   
   delay(1000);
  } 
    if (frequencyR > 130 && frequencyR<170 && frequencyG > 125 && frequencyG < 165 && frequencyB >140 && frequencyB < 180 ){
   Serial.println("Ph = 5");
   lcd.setCursor(0,1);
   lcd.print("Ph is 5");
   delay(1000);
    }
        if (frequencyR > 104 && frequencyR<154 && frequencyG > 135 && frequencyG < 165 && frequencyB >150 && frequencyB < 190 ){
   Serial.println("Ph = 6");
   lcd.setCursor(0,1);
   lcd.print("Ph is 6");
   delay(1000);
        } 
          if (frequencyR > 70 && frequencyR<110 && frequencyG > 108 && frequencyG < 148 && frequencyB >135 && frequencyB < 175 ){
   Serial.println("Ph = 6.6");
   lcd.setCursor(0,1);
   lcd.print("Ph is 6.5");
   delay(1000);
        } 
           if (frequencyR > 55 && frequencyR<95 && frequencyG > 95 && frequencyG < 135 && frequencyB >135 && frequencyB < 165 ){
   Serial.println("Ph = 7");
   lcd.setCursor(0,1);
   lcd.print("Ph is 7");
   delay(1000);
        }
           if (frequencyR > 45 && frequencyR<85 && frequencyG > 85 && frequencyG < 125 && frequencyB >114 && frequencyB < 154 ){
   Serial.println("Ph = 7.6");
   lcd.setCursor(0,1);
   lcd.print("Ph is 7.6");
   delay(1000);
        } 
           if (frequencyR > 65 && frequencyR<105 && frequencyG > 80 && frequencyG < 120 && frequencyB >110 && frequencyB < 150 ){
   Serial.println("Ph = 8.5");
   lcd.setCursor(0,1);
   lcd.print("Ph is 8.5");
   delay(1000);
        } 
           if (frequencyR > 112 && frequencyR<152 && frequencyG > 130 && frequencyG < 170 && frequencyB >156 && frequencyB < 196 ){
   Serial.println("Ph = 9");
   lcd.setCursor(0,1);
   lcd.print("Ph is 9");
   delay(1000);
        } 

            if (frequencyR > 93 && frequencyR<133 && frequencyG > 116 && frequencyG < 156 && frequencyB >140 && frequencyB < 180 ){
   Serial.println("Ph = 9.5");
   lcd.setCursor(0,1);
   lcd.print("Ph is 9.5");
   delay(1000);
        }
            if (frequencyR > 73 && frequencyR<113 && frequencyG > 103 && frequencyG < 143 && frequencyB >125 && frequencyB < 165 ){
   Serial.println("Ph = 10");
   lcd.setCursor(0,1);
   lcd.print("Ph is 10");
   delay(1000);
        }
   
}







