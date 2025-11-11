int sensorLus = A0;
int lus;

void setup() {
  Serial.begin(9600);
}

void loop() {
  lus = analogRead(sensorLus);
  Serial.println(lus);
  delay(1000);
}
