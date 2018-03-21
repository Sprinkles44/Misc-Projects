//Pins
int snd=13;
//int rtn=A0; 
int sensor, soundVal;

//Constants
int t, d; //Travel time of wave in microseconds. Distance traveled.
int thresh=1011; //Distance threshold value value before playing sound
int dly;

void setup() {
  Serial.begin(9600);
  pinMode(snd,OUTPUT);
  pinMode(A0,INPUT);
  pinMode(A5,INPUT);
  pinMode(0,OUTPUT);
  Serial.println("Device On.\n");
}

void loop() {
  digitalWrite(0,HIGH);
  dly=analogRead(A5);
//  Serial.println(dly);
  digitalWrite(snd,HIGH);
  delayMicroseconds(2);
  sensor=analogRead(A0);
  soundVal=sensor*8;
//  Serial.println(sensor);  
  if (sensor<thresh && sensor>0) {
    tone(A3,sensor);
    delay(dly);
  }
  else {
    noTone(A3);
  }
}

