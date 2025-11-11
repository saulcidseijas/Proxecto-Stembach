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



// ---- VARIABLES DE TEMPO ----
unsigned long tempoAnteriorLus = 0;
unsigned long tempoAnteriorDHT = 0;
unsigned long tempoAnteriorPir = 0;

// Intervalos en milisegundos
const unsigned long intervaloLus = 5000;  // cada 1 segundo
const unsigned long intervaloDHT = 5000;  // cada 2 segundos
const unsigned long intervaloPir = 5000;   // cada 0.5 segundos






void loop() {
  
  /*
  if (ValLus()>=950 && Movemento()==true){
    digitalWrite(R, HIGH);
    while(ValLus()>=950 && Movemento()==true){
      delay(2000);
    }
   
    digitalWrite(R, LOW);
    
  }
    //Comprobase a luz e se se detecta movemento acendese

  if (ValHumidade()>75){
    digitalWrite(B,HIGH);
    
    while (ValHumidade()>75){
      delay(500);
    }
    
    digitalWrite(B,LOW);
  }

  if(ValTemp()>23){
    digitalWrite(G, HIGH);

    while(ValTemp()>23){

      delay(1000);
    }

    digitalWrite(G, LOW);
  }
  delay(3000);*/




  unsigned long agora = millis();



 if (agora - tempoAnteriorLus >= intervaloLus) {
    tempoAnteriorLus = agora;
     if (ValLus()>=950 && Movemento()==true){
      digitalWrite(R, HIGH);
    
      
      
    }else digitalWrite(R, LOW);
  }

   if (agora - tempoAnteriorDHT >= intervaloDHT) {
    tempoAnteriorDHT = agora;
    if (ValHumidade()>75){
      digitalWrite(B,HIGH);
      
      
      
      
    }else digitalWrite(B,LOW); 


     if(ValTemp()>23){
      digitalWrite(G, HIGH);

     
   
    }else digitalWrite(G, LOW);
  }

    

   
    
    


}
