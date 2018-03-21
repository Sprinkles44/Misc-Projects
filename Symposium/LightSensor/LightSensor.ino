#define spkPin A5
#define snsPin A2
#define recPin 4
#define rled 5
int snsVal;
int atd=50; // Ambient light test duration. Number of values collected.
int sns=25; // Sensitivity of detectecting motion.
int amUp,amLow,avg;


void setup() {
  Serial.begin(9600);
  pinMode(rled,OUTPUT);
  pinMode(spkPin,OUTPUT); // Speaker
  collectAmbient();
}

void loop() {  
  snsVal=analogRead(snsPin);
  if (snsVal >= amUp || snsVal <= amLow) {
    tone(spkPin,snsVal);
    if (digitalRead(recPin)==HIGH) {
      digitalWrite(rled,HIGH);
      Serial.println(snsVal);   
    }
    else {
      digitalWrite(rled,LOW);
    }
  }
  else {
    noTone(spkPin);
    }
}

void collectAmbient() {
  int i=0;
  int sum=0;
  Serial.println("Ambient light readings:");
  for (i;i<=atd;i++) {
    snsVal=analogRead(snsPin);
    sum=sum+snsVal;
  }
  Serial.print("Sum: ");
  Serial.println(sum);
  avg= sum/atd;
  Serial.print("Average: ");
  Serial.println(avg);
  amUp=avg+sns; // Upper bound of ambient light
  amLow=avg-sns; // Lower bound of ambient light
  Serial.print("Ambient average: "); 
  Serial.println(avg);
  Serial.print("Lower Ambient bound: "); 
  Serial.println(amLow);
  Serial.print("Upper Ambient bound: "); 
  Serial.println(amUp);
}





