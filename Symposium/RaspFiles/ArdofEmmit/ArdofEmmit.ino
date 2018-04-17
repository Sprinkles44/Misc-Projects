#define led 13
#define snsPin A2

int snsVal;
int atd=50; // Ambient light test duration. Number of values collected.
int sns=15; // Sensitivity of detectecting motion.
int amUp,amLow,avg;


void setup() {
  pinMode(led,OUTPUT);
  Serial.begin(9600);
  collectAmbient();
}

void loop() {  
  snsVal=analogRead(snsPin);
  if (snsVal >= amUp || snsVal <= amLow) {
    Serial.println(snsVal);
  } else { 
    Serial.println(0);
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





