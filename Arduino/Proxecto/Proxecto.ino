/*
LCD:

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
#include <OneWire.h>
#include <DallasTemperature.h>
#include <LiquidCrystal.h>
#include <DHT.h>//libraria sensores dht
#include <SPI.h>//libraria sensores MAX6675 (Termopar)
//LCD 
const int rs = 12, en = 11, d4 = 5, d5 = 4, d6 = 3, d7 = 2;
LiquidCrystal lcd(rs, en, d4, d5, d6, d7);

//Pin Botón
const int boton = 8;

//DHT22
const int DHT22PIN1 = 48; 
const int DHT22PIN2 = 50;
const int DHT22PIN3 = 52;

DHT dht1(DHT22PIN1, DHT22);
DHT dht2(DHT22PIN2, DHT22);
DHT dht3(DHT22PIN3, DHT22);

//DHT 11:
const int DHT11PIN4 = 46;
const int DHT11PIN5 = 44;

DHT dht4(DHT11PIN4, DHT11);
DHT dht5(DHT11PIN5, DHT11);

float hum1,hum2,hum3,hum4,hum5;
float  temp1,temp2,temp3,temp4,temp5,tempMAX,tempDS1,tempDS2,tempDS3;

//MAX6675 Termopar
const int thermoDO = 49;
const int thermoCS = 51;
const int thermoCLK= 53;

//Sensor DS18b20
const int pinDatos1DQ = 43;
const int pinDatos2DQ = 45;
const int pinDatos3DQ = 47;

OneWire oneWireObjeto1(pinDatos1DQ);
OneWire oneWireObjeto2(pinDatos2DQ);
OneWire oneWireObjeto3(pinDatos3DQ);

DallasTemperature sensorDS18B20_1(&oneWireObjeto1);
DallasTemperature sensorDS18B20_2(&oneWireObjeto2);
DallasTemperature sensorDS18B20_3(&oneWireObjeto3);

/*Pin Lus
FotoRes1 =A0
FotoRes2 =A1
FotoRes3 =A2
*/

int lus1,lus2,lus3;
int i =0;


void setup() {
  //Inicialización da lcd
  lcd.begin(16, 2); 
  lcd.setCursor(0, 1);
  //Incialización botón
  pinMode(boton,LOW);
  //Incialización do porto serie
  Serial.begin(9600);
  //Inicialización dos DHT
  dht1.begin();
  dht2.begin();
  dht3.begin();
  dht4.begin();
  dht5.begin();
  //Inicialización dos DS18B20
  sensorDS18B20_1.begin();
  sensorDS18B20_2.begin();
  sensorDS18B20_3.begin();
  //Inicialización do MAX6675
  pinMode(thermoCS, OUTPUT);
  pinMode(thermoCLK, OUTPUT);
  pinMode(thermoDO, INPUT);
  digitalWrite(thermoCS, HIGH);
  SPI.begin();
}

void cont(){
  i=0;
  while (digitalRead(boton)==HIGH || i==10){
    delay(1000);
    i++;
  }
 
}

void SerialTemHum(){
  //Mostrar por pantalla os datos
    Serial.print("DHT22 1: ");
    Serial.print(temp1);
    Serial.print("ºC ");
    Serial.print(hum1);
    Serial.println("%");
    
    Serial.print("DHT22 2: ");
    Serial.print(temp2);
    Serial.print("ºC ");
    Serial.print(hum2);
    Serial.println("%");

    Serial.print("DHT22 3: ");
    Serial.print(temp3);
    Serial.print("ºC ");
    Serial.print(hum3);
    Serial.println("%");

    Serial.print("DHT11 4: ");
    Serial.print(temp4);
    Serial.print("ºC ");
    Serial.print(hum4);
    Serial.println("%");

    Serial.print("DHT11 5: ");
    Serial.print(temp5);
    Serial.print("ºC ");
    Serial.print(hum5);
    Serial.println("%");

    Serial.print("MAX6675: ");
    Serial.print(tempMAX);
    Serial.println("ºC");

    Serial.print("DS18B20 1:");
    Serial.print(tempDS1);
    Serial.println("ºC");

    Serial.print("DS18B20 2:");
    Serial.print(tempDS2);
    Serial.println("ºC");

    Serial.print("DS18B20 3:");
    Serial.print(tempDS3);
    Serial.println("ºC");
}

void lcdTempHum(){
  lcd.clear();
  lcd.home();
  lcd.print("DHT22 1: ");
  lcd.setCursor(0,2);
  lcd.print(temp1);
  lcd.print(" *C ");
  lcd.print(hum1);
  lcd.print("%");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DHT22 2: ");
  lcd.setCursor(0,2);
  lcd.print(temp2);
  lcd.print(" *C ");
  lcd.print(hum2);
  lcd.print("%");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DHT22 3: ");
  lcd.setCursor(0,2);
  lcd.print(temp3);
  lcd.print(" *C ");
  lcd.print(hum3);
  lcd.print("%");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DHT11 4: ");
  lcd.setCursor(0,2);
  lcd.print(temp4);
  lcd.print(" *C ");
  lcd.print(hum4);
  lcd.print("%");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DHT1 5: ");
  lcd.setCursor(0,2);
  lcd.print(temp5);
  lcd.print(" *C ");
  lcd.print(hum5);
  lcd.print("%");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("MAX6675:");
  lcd.setCursor(0,2);
  lcd.print(tempMAX);
  lcd.print(" *C ");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DS18B20 1:");
  lcd.setCursor(0,2);
  lcd.print(tempDS1);
  lcd.print(" *C ");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DS18B20 2:");
  lcd.setCursor(0,2);
  lcd.print(tempDS2);
  lcd.print(" *C ");
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("DS18B20 3:");
  lcd.setCursor(0,2);
  lcd.print(tempDS3);
  lcd.print(" *C ");
  cont();
      
}


float TempHum(){
  //Tomar os datos da temperatura dos sensores DHT
  temp1 = dht1.readTemperature();
  temp2 = dht2.readTemperature();
  temp3 = dht3.readTemperature();
  temp4 = dht4.readTemperature();
  temp5 = dht5.readTemperature();
 
  //Tomar os datos da humidade dos sensores DHT
  hum1 =dht1.readHumidity();
  hum2 =dht2.readHumidity();
  hum3 =dht3.readHumidity();
  hum4 =dht4.readHumidity();
  hum5 =dht5.readHumidity();

  //Tomar os datos da temperatura do sensor MAX6675
  digitalWrite(thermoCS, LOW);
  delay(1);
  uint16_t v = SPI.transfer16(0x0000);
  digitalWrite(thermoCS, HIGH);
  tempMAX = v*0.25;
  //Tomar os datos da temperatura do sensor DS18B20
  sensorDS18B20_1.requestTemperatures(); 
  sensorDS18B20_2.requestTemperatures(); 
  sensorDS18B20_3.requestTemperatures(); 
  tempDS1 = sensorDS18B20_1.getTempCByIndex(0);
  tempDS2 = sensorDS18B20_2.getTempCByIndex(0);
  tempDS3 = sensorDS18B20_3.getTempCByIndex(0);
  
  SerialTemHum();
  lcdTempHum();
  return 0;
}

int ValLus(){
  lus1= analogRead(A0);
  lus2= analogRead(A1);
  lus3= analogRead(A2);

  Serial.print("Luz 1:");
  Serial.println(lus1);
  Serial.print("Luz 2:");
  Serial.println(lus2);
  Serial.print("Luz 3:");
  Serial.println(lus3);

  lcd.clear();
  lcd.home();
  lcd.print("Luz 1:");
  lcd.print(lus1);
  cont();
  lcd.clear();
  
  lcd.home();
  lcd.print("Luz 2:");
  lcd.print(lus2);
  cont();
  lcd.clear();

  lcd.home();
  lcd.print("Luz 3:");
  lcd.print(lus3);
  cont();
  

  return 0;
}

void loop() {
  TempHum();
  ValLus();  
  }

    

   
    
    



