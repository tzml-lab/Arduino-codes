#include <dht.h>
#define dht11Pin 2
#define dhtType DHT11
dht DHT;
////////////////////////
#include <Wire.h>
#include <BH1750.h>
BH1750 lightMeter;
///////////////////////
#define soilPin A0
/////////////////////////
void setup() {
  Serial.begin(9600);
  Wire.begin();
  lightMeter.begin();
}


void loop() {
  // READ DATA
  /*
  Serial.print("DHT11, \t");
  int chk = DHT.read11(dht11Pin);
  switch (chk)
  {
    case DHTLIB_OK:  
		Serial.print("OK,\t"); 
		break;
    case DHTLIB_ERROR_CHECKSUM: 
		Serial.print("Checksum error,\t"); 
		break;
    case DHTLIB_ERROR_TIMEOUT: 
		Serial.print("Time out error,\t"); 
		break;
    default: 
		Serial.print("Unknown error,\t"); 
		break;
  }
 // DISPLAY DATA
 */
  int chk = DHT.read11(dht11Pin);
  Serial.print("Dht: ");
  Serial.print(DHT.humidity,1);
  Serial.print(" %,");
  Serial.print(DHT.temperature,1);
  Serial.print(" *C\t");
  ////////////////////////////////////////
  float lux = lightMeter.readLightLevel();
  Serial.print("Light: ");
  Serial.print(lux);
  Serial.print(" lx\t");
  ///////////////////////////////////////
  int sensorValue = analogRead(soilPin);
  Serial.print("Soil: ");
  Serial.println(sensorValue);
  delay(5000);
}
