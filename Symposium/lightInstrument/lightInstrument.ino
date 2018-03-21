#define spkPin A5
#define snsPin A2
#define recPin 2
#define rled 5
int snsVal;
int atd=50; // Ambient light test duration. Number of values collected.
int sns=15; // Sensitivity of detectecting motion.
int amUp,amLow,avg;
boolean rec=false;
int flag=0;

void setup() {
  pinMode(rled,OUTPUT);
  pinMode(spkPin,OUTPUT); // Speaker
  pinMode(recPin,INPUT_PULLUP);
  Serial.begin(9600);
  collectAmbient();
}

void loop() {  
  snsVal=analogRead(snsPin);
  recSwitch();
  if (rec==false) {
    playTone();
  }
  if (rec==true) {  
    recTone();
    flag=1;    
  }
  if (rec==false && flag==1) {
    Serial.println("end");
    flag=0;
  }
}

void playTone() {   
  if (snsVal >= amUp || snsVal <= amLow) {
    tone(spkPin,snsVal);
  } else { 
    noTone(spkPin);
  }
}

void recTone() {
  if (snsVal >= amUp || snsVal <= amLow) {
    tone(spkPin,snsVal);
    Serial.println(snsVal);
  } else { 
    noTone(spkPin);
    Serial.println(0);
  }
}

void recSwitch() {
  if (digitalRead(recPin)<HIGH) {
    rec=true;
    digitalWrite(rled,HIGH);
  } else {
    rec=false;
    digitalWrite(rled,LOW);
  }  
}

void collectAmbient() {
  int i=0;
  int sum=0;
  for (i;i<=atd;i++) {
    snsVal=analogRead(snsPin);
    sum=sum+snsVal;
  }
  avg= sum/atd;
  amUp=avg+sns; // Upper bound of ambient light
  amLow=avg-sns; // Lower bound of ambient light
}





