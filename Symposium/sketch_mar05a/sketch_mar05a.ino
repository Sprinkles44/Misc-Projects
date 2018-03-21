void setup() {
  Serial.begin(9600);
  for (int i=0;i<35;i++) {
    int val=analogRead(A0);
    Serial.println(val);
   }
}

void loop() {
  // put your main code here, to run repeatedly:

}
