//#include <SD.h>
//#include <SPI.h>

//File songFile;

//Pins
int outSensor=13; 
int sensor, soundVal;

//Constants
int thresh=1000; //Distance threshold value value before playing sound
int ps;

void setup() {
  Serial.begin(9600);
// LEDs
  pinMode(0,OUTPUT);
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(7,OUTPUT); 
//// "On" LED
//  pinMode(A4,OUTPUT);
//  pinMode(A2,OUTPUT);
  
// Record switch/button
  pinMode(6,INPUT); 
  
// Output electricity to sensor
  pinMode(outSensor,OUTPUT); // Pin 13
  
// Sensor data
  pinMode(A0,INPUT);
  
// Delay time change knob
  pinMode(A1,INPUT); 
  pinMode(8,OUTPUT);
//  songFile=SD.open("mySong.txt", FILE_WRITE);
  Serial.println("Device On.\n");
}

void loop() {
//  digitalWrite(A4,HIGH);
//  digitalWrite(A2,HIGH);
  int rec=digitalRead(6);
  digitalWrite(8,HIGH);
  ps=analogRead(A1);
  digitalWrite(outSensor,HIGH);
  delayMicroseconds(20);
  sensor=analogRead(A0);
  soundVal=sensor/2;  
  if (sensor<thresh && sensor>0) {
    tone(A3,soundVal);
    delay(ps/12);
    if (rec>LOW) {
      writeFile();
    }
    for (int i=0; i<15; i++) {
      selectLED(i);     
    }
  }
  else {
    noTone(A3);
  }
}


void led1() {
  digitalWrite(0,HIGH);
  digitalWrite(1,LOW);
}
void led2() {
  digitalWrite(1,HIGH);
  digitalWrite(0,LOW);
}
void led3() {
  digitalWrite(0,HIGH);
  digitalWrite(2,LOW);
}
void led4() {
  digitalWrite(2,HIGH);
  digitalWrite(0,LOW);
}
void led5() {
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
}
void led6() {
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
}
void led7() {
  digitalWrite(0,HIGH);
  digitalWrite(4,LOW);
}
void led8() {
  digitalWrite(4,HIGH);
  digitalWrite(0,LOW);
}
void led9() {
  digitalWrite(1,HIGH);
  digitalWrite(4,LOW);
}
void led10() {
  digitalWrite(4,HIGH);
  digitalWrite(1,LOW);
}
void led11() {
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
}
void led12() {
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
}
void led13() {
  digitalWrite(2,HIGH);
  digitalWrite(7,LOW);
}
void led14() {
  digitalWrite(7,HIGH);
  digitalWrite(2,LOW);
}
void led15() {
  digitalWrite(4,HIGH);
  digitalWrite(7,LOW);
}


void selectLED(int ledNo) {
  int n=ledNo;
  if (n==1)
    led1();
  else if (n==2)
    led2();
  else if (n==3)
    led3();
  else if (n==4)
    led4();
  else if (n==5)
    led5();
  else if (n==6)
    led6();
  else if (n==7)
    led7();
  else if (n==8)
    led8();
  else if (n==9)
    led9();
  else if (n==10)
    led10();
  else if (n==11)
    led11();
  else if (n==12)
    led12();
  else if (n==13)
    led13();
  else if (n==14)
    led14();
  else if (n==15)
    led15();     
}

void writeFile() {
  Serial.write(soundVal);
  Serial.write(",");
  Serial.write(ps);
  Serial.write(",");
}

//void saveFile() {
//  songFile.close();
//  Serial.println("Song file saved.");
//}
