// Pin do sensor PIR
const int PIR_PIN = 6;

// Variables de estado
int estadoAnterior = LOW;
int lectura = 0;

void setup() {
  pinMode(PIR_PIN, INPUT);
  Serial.begin(9600);
}

void loop() {
  lectura = digitalRead(PIR_PIN);

  if (lectura == HIGH && estadoAnterior == LOW) {
    Serial.println("Movemento detectado!");
    estadoAnterior = HIGH;
  }

  if (lectura == LOW && estadoAnterior == HIGH) {
    Serial.println("Movemento rematado");
    estadoAnterior = LOW;
  }
}

