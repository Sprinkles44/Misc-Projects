


void setup() {
  pinMode(1,OUTPUT);
  pinMode(2,OUTPUT);
  pinMode(3,OUTPUT);
  pinMode(4,OUTPUT);
  pinMode(5,OUTPUT);
}

void loop() {
  for (int i=0; i<15; i++){
    selectLED(i);     
  }
}

void led1() {
  digitalWrite(1,HIGH);
  digitalWrite(2,LOW);
}

void led2() {
  digitalWrite(2,HIGH);
  digitalWrite(1,LOW);
}

void led3() {
  digitalWrite(1,HIGH);
  digitalWrite(3,LOW);
}

void led4() {
  digitalWrite(3,HIGH);
  digitalWrite(1,LOW);
}

void led5() {
  digitalWrite(2,HIGH);
  digitalWrite(3,LOW);
}

void led6() {
  digitalWrite(3,HIGH);
  digitalWrite(2,LOW);
}

void led7() {
  digitalWrite(1,HIGH);
  digitalWrite(4,LOW);
}
void led8() {
  digitalWrite(4,HIGH);
  digitalWrite(1,LOW);
}

void led9() {
  digitalWrite(2,HIGH);
  digitalWrite(4,LOW);
}

void led10() {
  digitalWrite(4,HIGH);
  digitalWrite(2,LOW);
}

void led11() {
  digitalWrite(3,HIGH);
  digitalWrite(4,LOW);
}

void led12() {
  digitalWrite(4,HIGH);
  digitalWrite(3,LOW);
}

void led13() {
  digitalWrite(1,HIGH);
  digitalWrite(5,LOW);
}
void led14() {
  digitalWrite(5,HIGH);
  digitalWrite(1,LOW);
}

void led15() {
  digitalWrite(2,HIGH);
  digitalWrite(5,LOW);
}

void led16() {
  digitalWrite(5,HIGH);
  digitalWrite(2,LOW);
}

void led17() {
  digitalWrite(3,HIGH);
  digitalWrite(5,LOW);
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

