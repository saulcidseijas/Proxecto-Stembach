/*
Lcd pinout

E->11
RS->12
RW->Gnd
Vss-> gnd
Vcc-> 5V
V0-> pontenciometro 10k ohm
D4-> 5
D5-> 4
D6-> 3
D7-> 2
A -> 5V 
K-> gnd
*/
#include <LiquidCrystal.h>
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

#include <DHT.h>

#define DHTTYPE DHT11

const int DHTPIN1 = 3; 
const int DHTPIN2 = 4;
const int DHTPIN3 = 5;
const int DHTPIN4 = 6;
const int DHTPIN5 = 7;
 

DHT dht1(DHTPIN1, DHTTYPE);
DHT dht2(DHTPIN2, DHTTYPE);
DHT dht3(DHTPIN3, DHTTYPE);
DHT dht4(DHTPIN4, DHTTYPE);
DHT dht5(DHTPIN5, DHTTYPE);

float hum1;
float hum2;
float hum3;
float hum4;
float hum5;


int lus1,lus2,lus3;
float  temp1,temp2,temp3,temp4,temp5;


void setup() {

  Serial.begin(9600);
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  lcd.begin(16, 2); 
  lcd.setCursor(0, 1);

}

int ValLus(){

  lus1= analogRead(A0);
  lcd.print("Lus Sensor 1: ");
  lcd.println(lus1);

  lus2= analogRead(A1);
  lcd.print("Lus Sensor 2: ");
  lcd.println(lus2);

  lus3= analogRead(A2);
  lcd.print("Lus Sensor 3: ");
  lcd.println(lus3);

  return 0;
}

float ValHumidade(){
  hum1 =dht1.readHumidity();
  Serial.print("Humidade sensor 1 (%): ");
  Serial.println(hum1);

  hum2 =dht2.readHumidity();
  Serial.print("Humidade sensor 2 (%): ");
  Serial.println(hum2);
  
  hum3 =dht3.readHumidity();
  Serial.print("Humidade sensor 3 (%): ");
  Serial.println(hum3);

  hum4 =dht4.readHumidity();
  Serial.print("Humidade sensor 4 (%): ");
  Serial.println(hum4);

  hum5 =dht5.readHumidity();
  Serial.print("Humidade sensor 5 (%): ");
  Serial.println(hum5);
  
  
  Serial.println(hum1);
  Serial.println(hum2);
  Serial.println(hum3);
  Serial.println(hum4);
  Serial.println(hum5);
  
  return 0;
}

float ValTemp(){
  temp1 = dht1.readTemperature();
  Serial.print("Temperatura sensor 1 (ºC): ");
  Serial.println(temp1);

  temp2 = dht2.readTemperature();
  Serial.print("Temperatura sensor 2 (ºC): ");
  Serial.println(temp2);

  temp3 = dht3.readTemperature();
  Serial.print("Temperatura sensor 3 (ºC): ");
  Serial.println(temp3);
  
  temp4 = dht4.readTemperature();
  Serial.print("Temperatura sensor 4 (ºC): ");
  Serial.println(temp4);

  temp5 = dht5.readTemperature();
  Serial.print("Temperatura sensor 5 (ºC): ");
  Serial.println(temp5);
  
  return 0;
}


void loop() {
  lcd.home();
  lcd.print("DHT22 1: ");
  lcd.setCursor(0,2);
  lcd.print("temp1");
  lcd.print("*C ");
  
  lcd.print("hum1");
  lcd.print("%");
  

  



  
  }