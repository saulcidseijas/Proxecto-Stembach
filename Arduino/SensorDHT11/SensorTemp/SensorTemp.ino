#include <DHT.h>

#define DHTTYPE DHT22
#define DHTPIN 53//pin conexión ao sensor

DHT dht(DHTPIN, DHTTYPE);

float humidade;

float temperatura;

void setup(){
  Serial.begin(9600);
  dht.begin();
}

void loop(){
  delay(1000);
  humidade =dht.readHumidity();
  temperatura =dht.readTemperature();
  /*Serial.print("Humidade: ");
  Serial.println(humidade);
  Serial.println("%");
  Serial.print("Temperatura: ");
  Serial.println(temperatura);
  Serial.println(" ºC");*/

  Serial.print(humidade);
  Serial.print(",");
  Serial.println(temperatura);



}