//Pins
int Trig=2;
int Echo=5; 
int led=8;

//Constants
int t, d; //Travel time of wave in microseconds. Distance traveled.
int wallDist=60; //Distance before notification
int spd;

void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  Serial.println("Device On.\n");
}

void loop() {
  findDist();
  proximity();
  
}

void findDist() {
    digitalWrite(Trig,LOW);
    delayMicroseconds(2);
    digitalWrite(Trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig,LOW);
    t=pulseIn(Echo,HIGH);
    d=t*.034/2;
//    Serial.print("Distance: ");
//    Serial.print(d);
//    Serial.println(" cm\n");
//    delay(100);
}

void proximity() {
  spd=7*d;
  if (d<wallDist && d>0) {
    digitalWrite(led,HIGH);
    delay(spd);
    digitalWrite(led,LOW);
    delay(spd);
  }
}


