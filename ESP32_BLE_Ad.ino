
#include "sys/time.h"

#include "BLEDevice.h"
#include "BLEUtils.h"
#include "BLEBeacon.h"

#ifdef __cplusplus
extern "C" {
#endif

//uint8_t g_phyFuns;

#ifdef __cplusplus
}
#endif

// See the following for generating UUIDs:
// https://www.uuidgenerator.net/
BLEAdvertising *pAdvertising;


void setup() {

    
  Serial.begin(115200);
  // Create the BLE Device
  BLEDevice::init("CSIE_DevBLE_Beacon02");

  // Create the BLE Server
  // BLEServer *pServer = BLEDevice::createServer(); // <-- no longer required to instantiate BLEServer, less flash and ram usage

  pAdvertising = BLEDevice::getAdvertising();
  
  //setBeacon();
   // Start advertising
  pAdvertising->start();

}

void loop() {
}
