#include <SPI.h>

// Define MAX6675 SPI pins
const int thermoDO = 5;
const int thermoCS = 4;
const int thermoCLK = 6;

void setup() {
  // Initialize serial communication
  Serial.begin(9600);
  
  // Set SPI pins to output
  pinMode(thermoCS, OUTPUT);
  pinMode(thermoCLK, OUTPUT);
  pinMode(thermoDO, INPUT);

  // Disable device to start with
  digitalWrite(thermoCS, HIGH);
  
  // Initialize SPI
  SPI.begin();
}

double readTemperature() {
  // Ensure CS is low to enable the module
  digitalWrite(thermoCS, LOW);
  delay(1);
  
  // Read temperature data
  uint16_t v = SPI.transfer16(0x0000);
  
  // Disable the module
  digitalWrite(thermoCS, HIGH);
  
  // Process the raw data
  if (v & 0x4) {
    // Detect if thermocouple is disconnected
    return NAN; // Return Not-A-Number
  }
  
  // Remove unused bits
  v >>= 3;
  
  // Convert to Celsius
  return v*0.25;
}

void loop() {
  // Read and print temperature
  double temperature = readTemperature();
  if (!isnan(temperature)) {
    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.println(" C");
  } else {
    Serial.println("Error: Thermocouple disconnected!");
  }
  
  // Wait for a bit before reading again
  delay(2000);
}