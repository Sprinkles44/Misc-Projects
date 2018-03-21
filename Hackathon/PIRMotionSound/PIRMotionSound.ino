int sensor=7;
int sensorVal;
int led=12;

void setup() {
  Serial.begin(9600);
  pinMode(sensor,INPUT);
  pinMode(led,OUTPUT);
  Serial.println("Device on ");
}

void loop() {
  sensorVal=digitalRead(sensor);
  if (sensorVal==HIGH) {
    digitalWrite(led,HIGH);
  } else {
    digitalWrite(led,LOW);
  }
}
