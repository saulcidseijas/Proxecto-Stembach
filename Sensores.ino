#include <DHT.h>

#define DHTTYPE DHT11
#define DHTPIN 7 

DHT dht(DHTPIN, DHTTYPE);

const int sensorPir = 6;
const int sensorLus = A0;
int lus;
float humidade, temperatura;
int estadoAnterior = LOW;
int lectura = 0;

const int R=8;
const int G=9;
const int B=10;


void setup() {
  Serial.begin(9600);
  dht.begin();
  pinMode(sensorPir, INPUT);

//Led pins
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
}

int ValLus(){

  lus= analogRead(sensorLus);
  Serial.print("Lus: ");
  Serial.println(lus);
  return lus;
}

float ValHumidade(){
  humidade =dht.readHumidity();
  Serial.print("Humidade (%): ");
  Serial.println(humidade);
   return humidade;
}

float ValTemp(){
  temperatura = dht.readTemperature();
  Serial.print("Temperatura (ºC): ");
  Serial.println(temperatura);
  return temperatura;
}

bool Movemento(){
  lectura = digitalRead(sensorPir);

  if (lectura == HIGH && estadoAnterior == LOW) {
    Serial.println("Movemento detectado!");
    estadoAnterior = HIGH;
    return true;
  }

  if (lectura == LOW && estadoAnterior == HIGH) {
    Serial.println("Movemento rematado");
    estadoAnterior = LOW;
    return false;
  }
}


void loop() {
  
  
  if (ValLus()>=950 && Movemento()==true){
    digitalWrite(R, HIGH);
   
    delay(15000);
  }else{
    digitalWrite(R, LOW);
    delay(1000);
  }
    //Comprobase a luz e se se detecta movemento acendese

  if (ValHumidade()>75){
    digitalWrite(B,HIGH);
    delay(500);
    digitalWrite(B,LOW);
  }

}
