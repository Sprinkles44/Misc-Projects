//Pins
int Trig=2;
int Echo=5; 
int btIn=12; // Receives button press
int btOut=13; // Powers button


//Constants
int thresh=450; // Button press threshold
int t, d; //Travel time of wave in microseconds. Distance traveled.




void setup() {
  Serial.begin(9600);
  pinMode(Trig,OUTPUT);
  pinMode(Echo,INPUT);
  pinMode(btnIn,INPUT);
  pinMode(btnOut,OUTPUT);
  Serial.println("Device On. Press button to find distance. \n");
}

void loop() {
  digitalWrite(btnOut,HIGH);
  if (digitalRead(btn)>LOW) {
  findDist();
  } 
}

void findDist() {
    digitalWrite(Trig,LOW);
    delayMicroseconds(2);
    digitalWrite(Trig,HIGH);
    delayMicroseconds(10);
    digitalWrite(Trig,LOW);
    t=pulseIn(Echo,HIGH);
    d=t*.034/2;
    Serial.print("Distance: ");
    Serial.print(d);
    Serial.println(" cm\n");
    delay(1000);
}

