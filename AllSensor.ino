#include <dht.h>
#include<stdio.h>
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
  Serial.print("data");
  Serial.print(",");
  int chk = DHT.read11(dht11Pin);
  Serial.print(DHT.temperature,1);
  Serial.print(",");
  Serial.print(DHT.humidity,1);
  Serial.print(",");
  ///////////////////////////////////////
  int sensorValue = analogRead(soilPin);
  //Serial.print("Soil: ");
  int arr4[4] = {0};
  arr4[0] = sensorValue/1000;
  sensorValue = sensorValue%1000;
  arr4[1] = sensorValue/100;
  sensorValue = sensorValue%100;
  arr4[2] = sensorValue/10;
  sensorValue = sensorValue%10;
  arr4[3] = sensorValue;
  for(int i = 0; i < 4;i++){
    Serial.print(arr4[i]);
  }
  Serial.print(",");
  //Serial.write("55555");
  //Serial.write(",");
  ////////////////////////////////////////
  float lux = lightMeter.readLightLevel();
  //Serial.print("Light: ");
  long int lux_temp = lux*100;
  int arr7[7] = {0};
  arr7[0] = lux_temp/100000;
  lux_temp = lux_temp%100000;
  arr7[1] = lux_temp/10000;
  lux_temp = lux_temp%10000;
  arr7[2] = lux_temp/1000;
  lux_temp = lux_temp%1000;
  arr7[3] = lux_temp/100;
  lux_temp = lux_temp%100;
  arr7[5] = lux_temp/10;
  lux_temp = lux_temp%10;
  arr7[6] = lux_temp;
  for(int i = 0; i < 7;i++){
    if(i == 4)
      Serial.print(".");
    else
      Serial.print(arr7[i]);
  }
  Serial.println(",");
  
  delay(5000);
  Serial.flush();
}
